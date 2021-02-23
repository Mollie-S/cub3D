/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_handling.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:10:39 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/23 20:12:38 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HANDLING_H
# define KEY_HANDLING_H

# include "game_engine_state.h"

# define KEYCODE_ESC 53
# define KEYCODE_LEFT 123
# define KEYCODE_RIGHT 124
# define KEYCODE_W 13 
# define KEYCODE_S 1
# define KEYCODE_A 0
# define KEYCODE_D 2
# define KEYCODE_P 35

int		setup_key_hooks(t_game_engine_state *state);
int		key_pressed(int keycode, t_game_engine_state *state);
int		key_released(int keycode, t_game_engine_state *state);
#endif
