/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:10:15 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/06 20:06:54 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "key_handling.h"
#include "movement.h"
#include "bitmap.h"
#include "exit.h"

#include "mlx.h"

#include <stdlib.h>

int	setup_key_hooks(t_game_engine_state *state)
{
	mlx_hook(state->window->mlx_win, 2, 1L << 0, key_pressed, state);
	mlx_hook(state->window->mlx_win, 3, 1L << 1, key_released, state);
	mlx_hook(state->window->mlx_win, 17, 0L, exit_window, state);
	return (0);
}

int	key_pressed(int keycode, t_game_engine_state *state)
{
	if (keycode == KEYCODE_LEFT)
		state->move.rotation_dir = ROT_LEFT;
	else if (keycode == KEYCODE_RIGHT)
		state->move.rotation_dir = ROT_RIGHT;
	else if (keycode == KEYCODE_W)
		state->move.move_ver_dir = MOVE_FORWARD;
	else if (keycode == KEYCODE_S)
		state->move.move_ver_dir = MOVE_BACKWARD;
	else if (keycode == KEYCODE_A)
		state->move.move_hor_dir = MOVE_LEFT;
	else if (keycode == KEYCODE_D)
		state->move.move_hor_dir = MOVE_RIGHT;
	else if (keycode == KEYCODE_P)
		create_bmp_file(state);
	else if (keycode == KEYCODE_ESC)
		exit(0);
	return (0);
}

int	key_released(int keycode, t_game_engine_state *state)
{
	if (keycode == KEYCODE_LEFT || keycode == KEYCODE_RIGHT)
	{
		state->move.rotation_dir = 0;
	}
	else if (keycode == KEYCODE_W || keycode == KEYCODE_S)
	{
		state->move.move_ver_dir = 0;
	}
	else if (keycode == KEYCODE_A || keycode == KEYCODE_D)
	{
		state->move.move_hor_dir = 0;
	}
	if (keycode == KEYCODE_ESC)
		exit(0);
	return (0);
}
