/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:23:11 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/11 10:50:01 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw_frame.h"

#include "mlx.h"

void	draw_vertical_line(t_game_engine_state *state, t_intersection_result *result, int x)
{
	int				wall_top;
	int				wall_bottom;
	char 			*dst;
	int				y;
	unsigned int	color;

	wall_top = state->style->resolution.y / 2 - (int)result->wall_height / 2;
	wall_bottom = state->style->resolution.y / 2 + (int)result->wall_height / 2;
	dst = state->window->addr + x * (state->window->bits_per_pixel / 8);
	y = 0;
	while (y < state->style->resolution.y)
	{
		if (y < wall_top)
			color = state->style->ceiling_rgb;
		else if (y >= wall_top && y < wall_bottom)
		{
			result->tex_y = ((double)y - wall_top) / (wall_bottom - wall_top);
			color = sample_texture(state, result);
		}
		else
			color = state->style->floor_rgb;
		*(unsigned int*)dst = color;
		y++;
		dst += state->window->line_length;
	}
}

unsigned int	sample_texture(t_game_engine_state *state, t_intersection_result *result)
{
	char	*tex_color;
	int x;
	int y;

	// check that x and y are not less than 0 (clamp coordinates) nice to have
	x = result->tex_x * state->tex_info->img_width;
	y = result->tex_y * state->tex_info->img_height;

	tex_color = state->tex_info->addr + y * state->tex_info->line_length + x * (state->tex_info->bpp / 8);
	return (*(unsigned int*)tex_color);
}