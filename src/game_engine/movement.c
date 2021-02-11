/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:13:42 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/11 18:18:04 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "movement.h"
#include "utils.h"

#include <math.h>

void	init_movement(t_movement *move)
{
	move->rotation_dir = 0;
	move->move_ver_dir = 0;
	move->move_hor_dir = 0;
}

void	rotate_player(t_game_engine_state *state)
{
	if (state->move.rotation_dir == ROT_LEFT)
		state->direction -= ROT_SPEED;
	else if (state->move.rotation_dir == ROT_RIGHT)
		state->direction += ROT_SPEED;
	state->direction = wrap_angle(state->direction);
}

void	move_player(t_game_engine_state *state)
{

	if (state->move.move_ver_dir == MOVE_FORWARD || state->move.move_ver_dir == MOVE_BACKWARD)
	{
		move_back_forth(state);
	}
	if (state->move.move_hor_dir == MOVE_LEFT || state->move.move_hor_dir == MOVE_RIGHT)
	{
		move_left_right(state);
	}
}

void		move_back_forth(t_game_engine_state *state)
{
	double x_displacement;
	double y_displacement;

	x_displacement = sin(DEG2RAD(-state->direction)) * MOVE_SPEED;
	y_displacement = cos(DEG2RAD(-state->direction)) * MOVE_SPEED;
	if (state->move.move_ver_dir == MOVE_FORWARD)
	{
		state->pos_x -= x_displacement;
		state->pos_y -= y_displacement;
	}
	else
	{
		state->pos_x += x_displacement;
		state->pos_y += y_displacement;
	}
}

void		move_left_right(t_game_engine_state *state)
{
	double x_displacement;
	double y_displacement;

	x_displacement = cos(DEG2RAD(state->direction)) * MOVE_SPEED;
	y_displacement = sin(DEG2RAD(state->direction)) * MOVE_SPEED;
	if (state->move.move_hor_dir == MOVE_LEFT)
	{
		state->pos_x -= x_displacement;
		state->pos_y -= y_displacement;
	}
	else
	{
		state->pos_x += x_displacement;
		state->pos_y += y_displacement;
	}
