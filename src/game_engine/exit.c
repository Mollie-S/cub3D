/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 17:38:36 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/06 20:07:09 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

#include "mlx.h"

#include <stdlib.h>

int	exit_window(t_game_engine_state *state)
{
	mlx_destroy_window(state->window->mlx, state->window->mlx_win);
	exit(0);
	return (0);
}
