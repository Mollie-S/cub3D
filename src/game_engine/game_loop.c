/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 20:58:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 20:59:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "movement.h"
#include "utils.h"
#include "key_handling.h"
#include "raycasting/render_frame.h"

#include "mlx.h"

#include <math.h>

int		update_frame(t_game_engine_state *state)
{
	if (state->move.rotation_dir != 0)
		rotate_player(state);
	mlx_clear_window(state->window->mlx, state->window->mlx_win);
	render_frame(state);
	return (0);
}

void		init_game_engine_state(t_game_engine_state *state, t_window *window, t_style *style, t_map *map)
{
	state->window = window;
	state->style = style;
	state->map = map;
	state->dist_to_plane = (style->resolution.x / 2.0) / tan(DEG2RAD(FOV / 2.0));
	state->pos_x = map->start_pos_x + 0.5;
	state->pos_y = map->start_pos_y + 0.5;
	state->direction = map->start_direction;
}


void	game_loop(t_window *window, t_style *style, t_map *map)
{
	t_game_engine_state			state;
	t_movement					move;

	init_game_engine_state(&state, window, style, map);
	init_movement(&move);
	setup_key_hooks(&state);
	mlx_loop_hook(window->mlx, update_frame, &state);
	mlx_loop(window->mlx);
}

