/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_handling.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:10:39 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/11 14:36:17 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HANDLING_H
# define KEY_HANDLING_H

# include "game_engine_state.h"

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define W 13 
# define S 1
# define A 0
# define D 2

int		setup_key_hooks(t_game_engine_state *state);
int		key_pressed(int keycode, t_game_engine_state *state);
int		key_released(int keycode, t_game_engine_state *state);
#endif
