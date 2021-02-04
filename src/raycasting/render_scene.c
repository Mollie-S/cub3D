/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/04 18:19:53 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h> //remove

#include "render_scene.h"

/*
**	horizontal intersection
**  you can see that the distance between xi is the same
**		0°
**    |____/next xi_________
** 	  |   /								if we know the angle
**    |__/_next xi_________ 	90°	 	as our 0 axis is vertical we measure our angle from vertical 0
**    | /                           	slope = tan(angle) = dist between xi's / height
**   _|/____________                	so:dist between xi and next xi = height * tan where height = TILE_SIZE
**  xi|
**					 distance between xi = x_step;
** 		180°
*/


double			distance_to_wall(t_intersection *intersection, t_engine_state *engine_state, t_map *map, double radian)
{
	size_t		field_index;
	double		distance;


	distance = 0;
	while (intersection->x < map->width && intersection->y < map->height)
	{
		field_index = map->width * (size_t)intersection->y + (size_t)intersection->x;
		if (map->fields[field_index] == FIELD_WALL)
		{
			distance = fabs((engine_state->pos_x - intersection->x) / cos(radian)); // if cos(radian) == 0? it should be 1
			break ;
		}
		intersection->x += intersection->step_x;
		intersection->y += intersection->step_y;
	}
	return (distance);
}

double		calc_dist_on_horiz_inters(t_engine_state *engine_state, t_map *map, double ray_angle, double radian)
{
	t_intersection	horiz_intersection;

	horiz_intersection.y = floor(engine_state->pos_y) - TILE_SIZE;
	horiz_intersection.step_y = -TILE_SIZE;
	if (ray_angle >= 90 && ray_angle < 270)
	{
		horiz_intersection.y = floor(engine_state->pos_y) + TILE_SIZE;
		horiz_intersection.step_y = TILE_SIZE;
	}
	horiz_intersection.x = engine_state->pos_x + fabs((engine_state->pos_y - horiz_intersection.y) * tan(radian));
	horiz_intersection.step_x = TILE_SIZE * fabs(tan(radian));
	if (ray_angle >= 180 && ray_angle < 360)
	{
		horiz_intersection.x = engine_state->pos_x - fabs((engine_state->pos_y - horiz_intersection.y) * tan(radian));
		horiz_intersection.step_x = -horiz_intersection.step_x;
	}
	printf("horiz_x_step: %g\n", horiz_intersection.step_x);
	printf("horiz_y_step: %g\n", horiz_intersection.step_y);
	printf("horiz_intersection.x:%g\n", horiz_intersection.x);
	printf("horiz_intersection.y:%g\n", horiz_intersection.y);
	return (distance_to_wall(&horiz_intersection, engine_state, map, radian));
}

/*
**	find vertical intersection
**  you can see that the distance between xi is the same
**		0°
**    |   | /
** 	  |   |/							if we know the angle
**    |  /|next yi       	90°	 	  as our 0 axis is vertical we measure our angle from vertical 0
**    | / |                         	slope = tan(angle) = width / dist between yi's
**    |/  |              	so: dist between yi = width / tan(angle) where width = TILE_SIZE
**   /|yi
**					 distance between yi = y_step;
** 		180°
**
*/

double		calc_dist_on_vert_inters(t_engine_state *engine_state, t_map *map, double ray_angle, double radian)
{
	t_intersection	vert_intersection;

	vert_intersection.x = floor(engine_state->pos_x) + TILE_SIZE;
	vert_intersection.step_x = TILE_SIZE;
	if (ray_angle >= 180 && ray_angle < 360)
	{
		vert_intersection.x = floor(engine_state->pos_x) - TILE_SIZE;
		vert_intersection.step_x = -vert_intersection.step_x;
	}
	vert_intersection.y = engine_state->pos_y - fabs((engine_state->pos_x - vert_intersection.x) / tan(radian));
	vert_intersection.step_y = -TILE_SIZE / fabs(tan(radian));
	if (ray_angle >= 90 && ray_angle < 270)
	{
		vert_intersection.y = engine_state->pos_y + fabs((engine_state->pos_x - vert_intersection.x) / tan(radian));
		vert_intersection.step_y = -vert_intersection.step_y;
	}
	printf("vert_x_step: %g\n", vert_intersection.step_x);
	printf("vert_y_step: %g\n", vert_intersection.step_y);
	printf("vert_x:%g\n", vert_intersection.x);
	printf("vert_y:%g\n", vert_intersection.y);
	return (distance_to_wall(&vert_intersection, engine_state, map, radian));
}

double		calculate_dist_to_wall(t_engine_state *engine_state, t_map *map, double ray_angle, double radian)
{
	double	dist_horiz;
	double	dist_vert;

	printf("ray angle: %g\n", ray_angle);
	printf("pos_x: %g\n", engine_state->pos_x);
	printf("pos_y: %g\n", engine_state->pos_y);
	dist_horiz = calc_dist_on_horiz_inters(engine_state, map, ray_angle, radian);
	dist_vert = calc_dist_on_vert_inters(engine_state, map, ray_angle, radian);
	printf("dist_horiz: %g\n", dist_horiz);
	printf("dist_vert: %g\n", dist_vert);
	if (dist_horiz < dist_vert)
		return (dist_horiz);
	return (dist_vert);
}

// struct intersection_result
// {
// 	distance;

// pointer_to the texture;
// texture_coordinate;

// };


void		init_engine_state(t_engine_state *engine_state, t_map *map)
{
	engine_state->FOV = 60.0;
	engine_state->pos_x = map->start_pos_x + 0.5;
	engine_state->pos_y = map->start_pos_y + 0.5;
}

/*
**	adding (double)(0.0001) to radian to avoid division by 0 in case with tan(radian) or cos(radian)
*/

void		render_scene(t_map *map)
{
	t_engine_state	engine_state;
	double			ray_angle;
	double			radian;
	double			dist_to_wall;

	init_engine_state(&engine_state, map);
	ray_angle = map->start_direction - engine_state.FOV / 2.0;
	radian = ray_angle * (M_PI / 180) + (double)(0.0001);
	// I need to loop n times (pix per pix through resolution )to draw lines
	dist_to_wall = calculate_dist_to_wall(&engine_state, map, ray_angle, radian);
}
