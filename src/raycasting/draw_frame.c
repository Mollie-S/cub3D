/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:23:11 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/12 22:51:19 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "draw_frame.h"
#include "utils.h"
#include "sample_skybox.h"
#include "draw_utils.h"

#include "mlx.h"

void	draw_vertical_line(t_game_engine_state *state,
	t_intersection_result *result, int x, double ray_angle)
{
	int		wall_top;
	int		wall_bottom;
	char	*dst;
	int		y;

	wall_top = state->style->resolution.y / 2 - (int)result->wall_height / 2;
	wall_bottom = state->style->resolution.y / 2 + (int)result->wall_height / 2;
	dst = state->window->addr + x * (state->window->bits_per_pixel / 8);
	y = 0;
	while (y < state->style->resolution.y)
	{
		if (y < wall_top)
			*(unsigned int *)dst = draw_ceiling(state, y, ray_angle);
		else if (y >= wall_top && y < wall_bottom)
		{
			result->tex_y = ((double)y - wall_top) / (wall_bottom - wall_top);
			*(unsigned int *)dst = sample_texture(result->current_tex,
					result->tex_x, result->tex_y);
		}
		else
			*(unsigned int *)dst = state->style->floor_rgb;
		y++;
		dst += state->window->line_length;
	}
}

unsigned int	draw_ceiling(t_game_engine_state *state, int y, double angle)
{
	unsigned int	color;

	if (BONUS && state->style->textures[TEXTURE_SKYBOX] != NULL)
		color = sample_skybox(state, y, angle);
	else
		color = state->style->ceiling_rgb;
	return (color);
}

unsigned int	sample_texture(t_texture_info *tex, double tex_x, double tex_y)
{
	char	*tex_color;
	int		x;
	int		y;

	x = tex_x * tex->img_width;
	y = tex_y * tex->img_height;
	if (x < 0)
		x = 0;
	else if (x >= tex->img_width)
		x = tex->img_width - 1;
	if (y < 0)
		y = 0;
	else if (y >= tex->img_height)
		y = tex->img_height - 1;
	tex_color = tex->addr + y * tex->line_length + x * (tex->bpp / 8);
	return (*(unsigned int *)tex_color);
}

/*
**  It would be more readable to assign the  address like in wall draw:
** 	dst = state->window->addr + x * (state->window->bits_per_pixel / 8)
**		+ y * state->window->line_length;
**  and then to assign color to dst
**  but because of 25  I have to write an ugly solution
**
**  t_sprite *sp stands for *sprite - also 25 lines :( 
*/

void	draw_sprites_vertical_line(t_game_engine_state *state, int x,
	double dist_to_wall)
{
	int				i;
	int				y;
	unsigned int	color;
	t_sprite		*sp;

	i = 0;
	while (i < state->map->sprites_num)
	{
		sp = &state->sprites[i];
		if (sp->dist_to_sprite < dist_to_wall && sp->dist_to_sprite > 0.0
			&& x >= sp->draw_min_x && x <= sp->draw_max_x)
		{
			y = max(sp->draw_min_y, 0);
			while (y <= min(sp->draw_max_y, state->style->resolution.y - 1))
			{
				color = sample_sprites_vertical_line(state, x, y, i);
				if (color != 0x00000000)
					*(unsigned int *)(state->window->addr
							+ x * (state->window->bits_per_pixel / 8)
							+ y * state->window->line_length) = color;
				y++;
			}
		}
		i++;
	}
}

unsigned int	sample_sprites_vertical_line(t_game_engine_state *state,
	int x, int y, int i)
{
	double			sprite_tex_x;
	double			sprite_tex_y;
	unsigned int	color;

	sprite_tex_x = ((double)x - (state->sprites[i].draw_min_x))
		/ (state->sprites[i].draw_max_x - state->sprites[i].draw_min_x);
	sprite_tex_y = ((double)y - (state->sprites[i].draw_min_y))
		/ state->sprites[i].projected_height;
	color = sample_texture(&state->tex_info[TEXTURE_SPRITE],
			sprite_tex_x, sprite_tex_y);
	return (color);
}
