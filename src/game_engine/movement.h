/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:14:04 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/10 11:08:15 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# define ROT_LEFT -1
# define ROT_RIGHT 1
# define ROT_SPEED 1

#include "game_engine_state.h"

void	init_movement(t_movement *move);
void	rotate_player(t_game_engine_state *state);


#endif
