/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_loop.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 20:58:23 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 13:16:30 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H

# include "game_engine_state.h"

# define FOV 60

int		game_loop(t_window *window, t_style *style, t_map *map, int screenshot);
void	init_game_engine_state(t_game_engine_state *state, t_window *window,
			t_style *style, t_map *map);
int		update_frame(t_game_engine_state *state);

#endif
