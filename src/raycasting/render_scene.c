/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/03 18:28:35 by osamara       ########   odam.nl         */
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

double		calc_dist_on_horiz_inters(double pos_x, double pos_y, double direction, double radian, t_map *map)
{
	double	horiz_inters_x;
	double	horiz_inters_y;
	double 	horiz_x_step;
	double 	horiz_y_step;

	horiz_inters_y = floor(pos_y) - 1;
	horiz_y_step = -TILE_SIZE;
	if (direction >= 90 && direction < 270)
	{
		horiz_inters_y = floor(pos_y) + 1;
		horiz_y_step = TILE_SIZE;
	}
	horiz_inters_x = pos_x + fabs((pos_y - horiz_inters_y) * tan(radian));
	horiz_x_step = TILE_SIZE * fabs(tan(radian));
	if (direction >= 180 && direction < 360)
	{
		horiz_inters_x = pos_x - fabs((pos_y - horiz_inters_y) * tan(radian));
		horiz_x_step = -horiz_x_step;
	}
	printf("horiz_x_step: %g\n", horiz_x_step);
	printf("horiz_y_step: %g\n", horiz_y_step);
	printf("Hor_x:%g\n", horiz_inters_x);
	printf("Hor_y:%g\n", horiz_inters_y);

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

double		calc_dist_on_vert_inters(double pos_x, double pos_y, double direction, double radian, t_map *map)
{
	double	vert_inters_x;
	double	vert_inters_y;
	double 	vert_x_step;
	double 	vert_y_step;

	vert_inters_x = floor(pos_x) + 1;
	vert_x_step = TILE_SIZE;
	if (direction >= 180 && direction < 360)
	{
		vert_inters_x = floor(pos_x) - 1;
		vert_x_step = -TILE_SIZE;
	}
	vert_inters_y = pos_y - fabs((pos_x - vert_inters_x) / tan(radian));
	vert_y_step = -TILE_SIZE / fabs(tan(radian));
	if (direction >= 90 && direction < 270)
	{
		vert_inters_y = pos_y + fabs((pos_x - vert_inters_x) / tan(radian));
		vert_y_step = -vert_y_step; // it's not readable. do I leave it like this or do I change degrees in condition or do I calculate again without minus?
	}
	printf("vert_x_step: %g\n", vert_x_step);
	printf("vert_y_step: %g\n", vert_y_step);
	printf("vert_x:%g\n", vert_inters_x);
	printf("vert_y:%g\n", vert_inters_y);
}

double		calculate_dist_to_wall(t_engine_state *engine_state, t_map *map)
{
	double	pos_x;
	double	pos_y;
	double	direction;
	double	ray_angle;
	double	radian;
	double	dist_horiz;
	double	dist_vert;

	pos_x = engine_state->pos_x;
	pos_y = engine_state->pos_y;
	direction = map->start_direction - engine_state->FOV / 2;
	// ray_angle = (180 - engine_state->FOV) / 2; // must be changed
	ray_angle = direction;
	radian = ray_angle * (M_PI / 180);
	printf("direction: %g\n", direction);
	printf("pos_x: %g\n", pos_x);
	printf("pos_y: %g\n", pos_y);
	dist_horiz = calc_dist_on_horiz_inters(pos_x, pos_y, direction, radian, map); // I need to pass less params here. how? 
	dist_vert = calc_dist_on_vert_inters(pos_x, pos_y, direction, radian, map);
	printf("dist_horiz: %g\n", dist_horiz);
	printf("dist_vert: %g\n", dist_vert);
	if (dist_horiz < dist_vert)
		return (dist_horiz);
	return (dist_vert);
}

void		init_engine_state(t_engine_state *engine_state, t_map *map)
{
	engine_state->FOV = 60;
	engine_state->pos_x = map->start_pos_x + 0.5;
	engine_state->pos_y = map->start_pos_y + 0.5;
}

void		render_scene(t_map *map)
{
	t_engine_state	engine_state;
	double			dist_to_wall;

	init_engine_state(&engine_state, map);
	// I need to loop (FOV) times to draw (FOV num) of lines
	dist_to_wall = calculate_dist_to_wall(&engine_state, map);
}
