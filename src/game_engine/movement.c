/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:13:42 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 20:40:19 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"
#include "utils.h"

void	init_movement(t_movement *move)
{
	move->rotation_dir = 0;
}

void	rotate_player(t_game_engine_state *state)
{
	if (state->move.rotation_dir == ROT_LEFT)
		state->direction -= ROT_SPEED;
	else if (state->move.rotation_dir == ROT_RIGHT)
		state->direction += ROT_SPEED;
	state->direction = wrap_angle(state->direction);

}