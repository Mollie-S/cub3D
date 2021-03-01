/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:23:11 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 08:55:06 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw_frame.h"
#include "utils.h"
#include "sample_skybox.h"

#include "mlx.h"

void	draw_vertical_line(t_game_engine_state *state, t_intersection_result *result, int x, double ray_angle)
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
		{
			if (state->style->textures[TEXTURE_SKYBOX] != NULL)
				color = sample_skybox(state, y, ray_angle);
			else
				color = state->style->ceiling_rgb;
		}
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

void	draw_sprites_vertical_pixels(t_game_engine_state *state, int x, double dist_to_wall)
{
	int				i;
	int				y;
	unsigned int	color;
	double			sprite_tex_x;
	double			sprite_tex_y;
	char			*dst;

	i = 0;
	while (i < state->map->sprites_num)
	{
		if (state->sprites[i].dist_to_sprite < dist_to_wall
			&& state->sprites[i].dist_to_sprite > 0.0
			&& x >= state->sprites[i].draw_min_x && x <= state->sprites[i].draw_max_x)
		{
			y = state->sprites[i].draw_min_y;
			dst = state->window->addr + x * (state->window->bits_per_pixel / 8)
				+ y * state->window->line_length;
			while (y <= state->sprites[i].draw_max_y)
			{
				// draw_sprites_vertical_pixels(x, y, state)
				sprite_tex_x = ((double)x - (state->sprites[i].draw_min_x))
					/ (state->sprites[i].draw_max_x - state->sprites[i].draw_min_x);
				sprite_tex_y = ((double)y - (state->sprites[i].draw_min_y))
					/ state->sprites[i].projected_height;
				color = sample_texture(&state->tex_info[TEXTURE_SPRITE],
					sprite_tex_x, sprite_tex_y);
				if (color != 0x00000000)
					*(unsigned int *)dst = color;
				y++;
				dst += state->window->line_length;
			}
		}
		i++;
	}
}

unsigned int	sample_texture(t_texture_info *texture, double tex_x, double tex_y)
{
	char	*tex_color;
	int 	x;
	int 	y;

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
