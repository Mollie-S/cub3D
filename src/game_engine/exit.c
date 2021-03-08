/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 17:38:36 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/08 13:49:33 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

#include "mlx.h"

#include <stdlib.h>

int	exit_window(t_window *window)
{
	mlx_destroy_window(window->mlx, window->mlx_win);
	exit(0);
	return (0);
}
