/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:23:11 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 00:18:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw_scene.h"

#include "mlx.h"

void	draw_vertical_line(t_window *window, t_intersection_result *inters_res, t_resolution *resolution, int *num)
{
	int		line_start;
	int		line_end;
	int		x;
	int		y;

	line_start = resolution->y / 2 - (int)inters_res->wall_height / 2;
	line_end = resolution->y / 2 + (int)inters_res->wall_height / 2;
	y = line_start;
	while (y <= line_end)
	{
		x = *num;
		if (x == *num)
		{
			my_mlx_pixel_put(window, x, y, inters_res->current_color);
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_window *window, int x, int y, unsigned int color)
{
	char *dst;

	dst = window->address + (y * window->line_length + x * (window->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_image(t_window *window) // should be either removed or extended
{
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
	mlx_loop(window->mlx);
}
