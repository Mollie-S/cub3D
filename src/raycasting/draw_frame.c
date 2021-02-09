/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:23:11 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 21:47:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw_frame.h"

#include "mlx.h"

void	draw_vertical_line(t_game_engine_state *state, t_intersection_result *inters_res, int x)
{
	int		wall_top;
	int		wall_bottom;
	int				y;
	unsigned int	color;
	char *dst;


	wall_top = state->style->resolution.y / 2 - (int)inters_res->wall_height / 2;
	wall_bottom = state->style->resolution.y / 2 + (int)inters_res->wall_height / 2;
	dst = state->window->address + x * (state->window->bits_per_pixel / 8);
	y = 0;
	while (y < state->style->resolution.y)
	{
		if (y < wall_top)
			color = state->style->ceiling_rgb;
		else if (y >= wall_top && y < wall_bottom)
			color = inters_res->current_color;
		else
			color = state->style->floor_rgb;
		*(unsigned int*)dst = color;
		y++;
		dst += state->window->line_length;
	}
}


void	draw_image(t_window *window) // should be either removed or extended
{
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img, 0, 0);
}
