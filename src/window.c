/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 21:33:17 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 18:06:16 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

#include "result.h"
#include "report_error.h"

#include "mlx.h"
#include <stddef.h>

static void	check_plane_size(void *mlx, t_resolution *resolution)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(mlx, &sizex, &sizey);
	if (resolution->x > sizex || resolution->y > sizey)
	{
		resolution->x = sizex;
		resolution->y = sizey;
	}
}

int	start_window(t_window *window, t_resolution *resolution)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
	{
		return (report_error("Failed to connect to the graphical system"));
	}
	check_plane_size(window->mlx, resolution);
	window->mlx_win = mlx_new_window(window->mlx, resolution->x,
			resolution->y, "cub3D");
	window->img = mlx_new_image(window->mlx, resolution->x, resolution->y);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
			&window->line_length, &window->endian);
	return (SUCCESS);
}
