/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:14:04 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/11 22:20:40 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# define ROT_LEFT -1
# define ROT_RIGHT 1
# define ROT_SPEED 1
# define MOVE_SPEED 0.03
# define MOVE_FORWARD  -1
# define MOVE_BACKWARD 1
# define MOVE_RIGHT 1
# define MOVE_LEFT -1

# include "game_engine_state.h"

void	init_movement(t_movement *move);
void	rotate_player(t_game_engine_state *state);
void	move_player(t_game_engine_state *state);
void	move_back_forth(t_game_engine_state *state);
void	move_left_right(t_game_engine_state *state);

#endif
