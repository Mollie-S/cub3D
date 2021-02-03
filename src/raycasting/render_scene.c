/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/03 15:29:06 by osamara       ########   odam.nl         */
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

void	check_horizontal_intersection(double player_pos_x, double player_pos_y, double direction, double radian)
{
	double	horiz_inters_x;
	double	horiz_inters_y;

	horiz_inters_y = floor(player_pos_y) - 1;
	if (direction >= 90 && direction < 270)
	{
		horiz_inters_y = floor(player_pos_y) + 1;
	}
	horiz_inters_x = player_pos_x - fabs((player_pos_y - horiz_inters_y) * tan(radian));
	if (direction >= 0 && direction < 180)
	{
		horiz_inters_x = player_pos_x + fabs((player_pos_y - horiz_inters_y) * tan(radian));
	}
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

void	check_vertical_intersection(double player_pos_x, double player_pos_y, double direction, double radian)
{
	double	vert_inters_x;
	double	vert_inters_y;

	vert_inters_x = floor(player_pos_x) - 1;
	if (direction >= 0 && direction < 180)
	{
		vert_inters_x = floor(player_pos_x) + 1;
	}
	vert_inters_y = player_pos_y - fabs((player_pos_x - vert_inters_x) / tan(radian));
	if (direction >= 90 && direction < 270)
	{
		vert_inters_y = player_pos_y + fabs((player_pos_x - vert_inters_x) / tan(radian));
	}
	printf("vert_x:%g\n", vert_inters_x);
	printf("vert_y:%g\n", vert_inters_y);
}

void		find_wall(t_engine_state *engine_state, t_map *map)
{
	double	player_pos_x;
	double	player_pos_y;
	double	direction;
	double	ray_angle;
	double	radian;

	double 	horiz_x_step;
	double 	horiz_y_step;
	double 	vert_x_step;
	double 	vert_y_step;

	player_pos_x = engine_state->pos_x;
	player_pos_y = engine_state->pos_y;
	direction = map->start_direction - engine_state->FOV / 2;
	// ray_angle = (180 - engine_state->FOV) / 2; // must be changed
	ray_angle = direction;
	radian = ray_angle * (M_PI / 180);
	horiz_x_step = fabs(TILE_SIZE * tan(radian));
	horiz_y_step = -TILE_SIZE;
	if (direction >= 90 && direction < 270)
	{
		horiz_y_step = TILE_SIZE;
	}
	vert_y_step = fabs(TILE_SIZE / tan(radian));
	vert_x_step = -TILE_SIZE;
	if (direction >= 0 && direction < 180)
	{
		vert_x_step = TILE_SIZE;
	}
	printf("direction: %g\n", direction);
	printf("player_pos_x: %g\n", player_pos_x);
	printf("player_pos_y: %g\n", player_pos_y);
	printf("horiz_x_step: %g\n", horiz_x_step);
	printf("horiz_y_step: %g\n", horiz_y_step);
	printf("vert_x_step: %g\n", vert_x_step);
	printf("vert_y_step: %g\n", vert_y_step);
	check_horizontal_intersection(player_pos_x, player_pos_y, direction, radian);
	check_vertical_intersection(player_pos_x, player_pos_y, direction, radian);
}

void	init_engine_state(t_engine_state * engine_state, t_map * map)
{
	engine_state->FOV = 60;
	engine_state->pos_x = map->start_pos_x + 0.5;
	engine_state->pos_y = map->start_pos_y + 0.5;
}

void		render_scene(t_map * map)
{
	t_engine_state	engine_state;

	init_engine_state(&engine_state, map);
	find_wall(&engine_state, map);
}
