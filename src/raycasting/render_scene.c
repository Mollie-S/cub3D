/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/02 14:07:06 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h> //remove

#include "render_scene.h"

/*
**	find horizontal and vertical intersection
**
**  you can see that the distance between xi is the same
**  if we know the angle
**		0°
**    ___ |_/next xi_________
** 	      |
**   ____/|next xi_________ 	90°	  slope = tan = height / dist between xi's
**      / |
**   __/__|_________  dist between xi = height/tan where height=tile size
**  old xi|
**					 distance between xi = x_step[view_angle];
** 		180°
*/

void		find_wall(t_engine_state *engine_state, t_map *map)
{
	double	direction; // do I need it?
	double	ray_angle;
	double	radian;
	double 	x_check_step;
	double 	y_check_step;
	double	horiz_intersctn_x;
	double	horiz_intersctn_y;

	horiz_intersctn_y = 0;
	direction = map->start_direction;
	ray_angle = (180 - engine_state->FOV) / 2; // must be changed
	radian = ray_angle * (180 / M_PI);
	x_check_step = TILE_SIZE * tan(radian);
	y_check_step = TILE_SIZE / tan(radian);
	if (direction >= 90 && direction < 270)
	{
		horiz_intersctn_y = floor(engine_state->pos_y) + 1;
	}
	else
		horiz_intersctn_y = floor(engine_state->pos_y) - 1;
	horiz_intersctn_x = engine_state->pos_x + (engine_state->pos_y - horiz_intersctn_y) * tan(radian);
	printf("y:%g\n", horiz_intersctn_y);
	printf("x:%g\n", horiz_intersctn_x);
}


void	init_engine_state(t_engine_state *engine_state, t_map *map)
{
	engine_state->FOV = 60;
	engine_state->pos_x = map->start_pos_x + 0.5;
	engine_state->pos_y = map->start_pos_y + 0.5;
}

void		render_scene(t_map *map)
{
	t_engine_state	engine_state;

	init_engine_state(&engine_state, map);
	find_wall(&engine_state, map);
}
