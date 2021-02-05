/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/05 15:57:47 by osamara       ########   odam.nl         */
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


double			distance_to_wall(t_intersection *intersection, t_engine_state *engine_state, t_map *map)
{
	size_t		field_index;
	double		distance;

	distance = 0;
	while (intersection->x < map->width && intersection->y < map->height)
	{
		field_index = map->width * (size_t)intersection->y + (size_t)intersection->x;
		if (map->fields[field_index] == FIELD_WALL)
		{
			distance = fabs((engine_state->pos_x - intersection->x) / cos(engine_state->radian));
			break ;
		}
		intersection->x += intersection->step_x;
		intersection->y += intersection->step_y;
	}
	return (distance);
}

double		dist_to_hor_inters(t_engine_state *engine_state, t_map *map)
{
	t_intersection	hor_inters;

	hor_inters.y = floor(engine_state->pos_y) - TILE_SIZE;
	hor_inters.step_y = -TILE_SIZE;
	if (engine_state->ray_angle >= 90 && engine_state->ray_angle < 270)
	{
		hor_inters.y = floor(engine_state->pos_y) + TILE_SIZE;
		hor_inters.step_y = TILE_SIZE;
	}
	hor_inters.x = engine_state->pos_x + fabs((engine_state->pos_y - hor_inters.y) * tan(engine_state->radian));
	hor_inters.step_x = TILE_SIZE * fabs(tan(engine_state->radian));
	if (engine_state->ray_angle >= 180 && engine_state->ray_angle < 360)
	{
		hor_inters.x = engine_state->pos_x - fabs((engine_state->pos_y - hor_inters.y) * tan(engine_state->radian));
		hor_inters.step_x = -hor_inters.step_x;
	}
	printf("horiz_x_step: %g\n", hor_inters.step_x);
	printf("horiz_y_step: %g\n", hor_inters.step_y);
	printf("hor_inters.x:%g\n", hor_inters.x);
	printf("hor_inters.y:%g\n", hor_inters.y);
	return (distance_to_wall(&hor_inters, engine_state, map));
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

double		dist_to_ver_inters(t_engine_state *engine_state, t_map *map)
{
	t_intersection	vert_inters;

	vert_inters.x = floor(engine_state->pos_x) + TILE_SIZE;
	vert_inters.step_x = TILE_SIZE;
	if (engine_state->ray_angle >= 180 && engine_state->ray_angle < 360)
	{
		vert_inters.x = floor(engine_state->pos_x) - TILE_SIZE;
		vert_inters.step_x = -vert_inters.step_x;
	}
	vert_inters.y = engine_state->pos_y - fabs((engine_state->pos_x - vert_inters.x) / tan(engine_state->radian));
	vert_inters.step_y = -TILE_SIZE / fabs(tan(engine_state->radian));
	if (engine_state->ray_angle >= 90 && engine_state->ray_angle < 270)
	{
		vert_inters.y = engine_state->pos_y + fabs((engine_state->pos_x - vert_inters.x) / tan(engine_state->radian));
		vert_inters.step_y = -vert_inters.step_y;
	}
	printf("vert_x_step: %g\n", vert_inters.step_x);
	printf("vert_y_step: %g\n", vert_inters.step_y);
	printf("vert_x:%g\n", vert_inters.x);
	printf("vert_y:%g\n", vert_inters.y);
	return (distance_to_wall(&vert_inters, engine_state, map));
}

void		init_intersection_result(t_intersection_result *inters_result)
{
	inters_result->dist_to_wall = 0;
	inters_result->is_side_wall = 0;
	inters_result->current_texture = NULL;
	inters_result->texture_x = 0;
	inters_result->texture_y = 0;
}

/*
**	adding (double)(0.0001) to radian to avoid division by 0 in case with tan(radian) or cos(radian)
*/
void		init_engine_state(t_engine_state *engine_state, t_map *map)
{
	engine_state->FOV = 60.0;
	engine_state->pos_x = map->start_pos_x + 0.5;
	engine_state->pos_y = map->start_pos_y + 0.5;
	engine_state->ray_angle = map->start_direction - engine_state->FOV / 2.0;
	engine_state->radian = engine_state->ray_angle * (M_PI / 180) + (double)(0.0001);
}

//remove this function!
void		print_data(t_engine_state *engine_state,
	t_intersection_result *inters_result, t_map *map)
{

	printf("ray angle: %g\n", engine_state->ray_angle);
	printf("pos_x: %g\n", engine_state->pos_x);
	printf("pos_y: %g\n", engine_state->pos_y);
	printf("dist_horiz: %g\n", inters_result->dist_to_wall);
}

void		render_scene(t_map *map, t_style *style)
{
	t_engine_state			engine_state;
	// t_intersection			intersection;
	t_intersection_result	inters_result;
	double					dist_hor_inters;
	double					dist_ver_inters;

	init_engine_state(&engine_state, map);
	init_intersection_result(&inters_result);
	// I need to loop n times (pix per pix through resolution )to draw lines
	dist_hor_inters = dist_to_hor_inters(&engine_state, map);
	dist_ver_inters = dist_to_ver_inters(&engine_state, map);
	if (dist_ver_inters < dist_hor_inters)
	{
		inters_result.is_side_wall = 1;
		// if (intersection->) // how to check if the wall is right or left??
		inters_result.dist_to_wall = dist_ver_inters;
	}
	else
		inters_result.dist_to_wall = dist_hor_inters;
}