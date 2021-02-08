/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 20:58:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 00:02:03 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "raycasting/render_scene.h"
#include "utils.h"

#include <math.h>

void	game_loop(t_window *window, t_style *style, t_map *map)
{
	t_game_engine_state			state;

	init_game_engine_state(&state, window, style, map);
	render_scene(&state);
}

void		init_game_engine_state(t_game_engine_state *state, t_window *window, t_style *style, t_map *map)
{
	state->window = window;
	state->style = style;
	state->map = map;
	state->dist_to_plane = (style->resolution.x / 2.0) / tan(DEG2RAD(FOV / 2.0));
	state->pos_x = map->start_pos_x + 0.5;
	state->pos_y = map->start_pos_y + 0.5;
}

// mlx_loop_hook;
	// create a struct that combines the structs needed for rendering