/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:23:11 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/12 13:11:51 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw_frame.h"
#include "utils.h"

#include "mlx.h"

unsigned int		sample_skybox(t_game_engine_state *state, int y, double ray_angle)
{
	double skybox_x;
	double skybox_y;

	ray_angle = wrap_angle(ray_angle * 2.0);
	skybox_x = ray_angle / 360.0;
	skybox_y = (double)y / (state->style->resolution.y / 2.0);
	// if (bonus)
	return (sample_texture(state->tex_info, skybox_x, skybox_y));
	// else
	// return (state->style->ceiling_rgb);
}

void				draw_vertical_line(t_game_engine_state *state, t_intersection_result *result, int x, double ray_angle)
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
			color = sample_skybox(state, y, ray_angle);
		else if (y >= wall_top && y < wall_bottom)
		{
			result->tex_y = ((double)y - wall_top) / (wall_bottom - wall_top);
			color = sample_texture(result->current_tex, result->tex_x, result->tex_y);
		}
		else
			color = state->style->floor_rgb;
		*(unsigned int*)dst = color;
		y++;
		dst += state->window->line_length;
	}
}

unsigned int		sample_texture(t_texture_info *texture, double tex_x, double tex_y)
{
	char	*tex_color;
	int x;
	int y;

	// check that x and y are not less than 0 (clamp coordinates) nice to have
	x = tex_x * texture->img_width;
	y = tex_y * texture->img_height;

	if (x < 0)
		x = 0;
	else if (x >= texture->img_width)
		x = texture->img_width - 1;
	if (y < 0)
		y = 0;
	else if (y >= texture->img_height)
		y = texture->img_height - 1;

	tex_color = texture->addr + y * texture->line_length + x * (texture->bpp / 8);
	return (*(unsigned int*)tex_color);
}
