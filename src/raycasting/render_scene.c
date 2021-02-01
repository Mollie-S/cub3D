/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:25:09 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/01 22:17:16 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h> //remove

#include "render_scene.h"

/*
**	find horizontal intersection
*/

void		find_wall(t_engine_state *engine_state, t_map *map)
{
	int		direction; // do I need it?
	double	ray_angle;
	double	radian;
	double 	x_check_step;
	double 	y_check_step;
	int		horiz_intersctn_x;
	int		horiz_intersctn_y;

	direction = map->start_direction;
	ray_angle = (180 - engine_state->FOV) / 2;
	radian = ray_angle * (180 / M_PI);
	x_check_step = TILE_SIZE / tan(radian);
	y_check_step = TILE_SIZE * tan(radian);
	horiz_intersctn_y = floor(map->start_pos_y / TILE_SIZE) * TILE_SIZE;
	horiz_intersctn_x = map->start_pos_x + (map->start_pos_y - horiz_intersctn_y) / tan(radian);
	//    while (1)
	// {
	// 	if () // how to write these conditions???? if angle > 90 && angle < 270?
	// 	{
	// 	}
	// }
	printf("y:%d\n", horiz_intersctn_y);
	printf("x:%d\n", horiz_intersctn_x);
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
