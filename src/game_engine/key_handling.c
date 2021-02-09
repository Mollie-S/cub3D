/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 17:10:15 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 20:54:03 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "key_handling.h"
#include "result.h"

#include "mlx.h"

int		setup_key_hooks(t_game_engine_state *state)
{
	mlx_hook(state->window->mlx_win, 2, 1L << 0, key_pressed, state);
	mlx_hook(state->window->mlx_win, 3, 1L << 1, key_released, state);
	// mlx_hook(state->window->mlx_win, 17, 1L << 19, exit_window, state); add exit function
	return (SUCCESS);
}

int		key_pressed(int keycode, t_game_engine_state *state)
{

	if (keycode == LEFT || keycode == RIGHT)
	{
		if (keycode == LEFT)
			state->move.rotation_dir = -1;
		else
			state->move.rotation_dir = 1;
	}
	return (0);
}
int		key_released(int keycode, t_game_engine_state *state)
{

	if (keycode == LEFT || keycode == RIGHT)
	{
		state->move.rotation_dir = 0;
	}
	return (0);
}