/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:10:15 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/14 15:23:53 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "key_handling.h"
#include "movement.h"

#include "mlx.h"

#include <stdlib.h>

int		setup_key_hooks(t_game_engine_state *state)
{
	mlx_hook(state->window->mlx_win, 2, 1L << 0, key_pressed, state);
	mlx_hook(state->window->mlx_win, 3, 1L << 1, key_released, state);
	return (0);
}

int		key_pressed(int keycode, t_game_engine_state *state)
{
	if (keycode == LEFT || keycode == RIGHT)
	{
		if (keycode == LEFT)
			state->move.rotation_dir = ROT_LEFT;
		else
			state->move.rotation_dir = ROT_RIGHT;
	}
	else if (keycode == W || keycode == S)
	{
		if (keycode == W)
			state->move.move_ver_dir = MOVE_FORWARD;
		else
			state->move.move_ver_dir = MOVE_BACKWARD;
	}
	else if (keycode == A || keycode == D)
	{
		if (keycode == A)
			state->move.move_hor_dir = MOVE_LEFT;
		else
			state->move.move_hor_dir = MOVE_RIGHT;
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}

int		key_released(int keycode, t_game_engine_state *state)
{
	if (keycode == LEFT || keycode == RIGHT)
	{
		state->move.rotation_dir = 0;
	}
	else if (keycode == W || keycode == S)
	{
		state->move.move_ver_dir = 0;
	}
	else if (keycode == A || keycode == D)
	{
		state->move.move_hor_dir = 0;
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}