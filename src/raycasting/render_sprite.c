/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_sprite.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 14:26:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/12 00:23:42 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render_sprite.h"
#include "utils.h"
#include "game_engine/game_loop.h"

#include <math.h>

void	handle_sprites(t_game_engine_state *state)
{
	int	i;

	sort_sprites(state);
	i = 0;
	while (i < state->map->sprites_num)
	{
		calc_sprite_pos_on_screen(state, &state->sprites[i]);
		i++;
	}
}

void	sort_sprites(t_game_engine_state *state)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	calc_dist_to_sprites(state);
	while (i < state->map->sprites_num)
	{
		j = i + 1;
		while (j < state->map->sprites_num)
		{
			if (state->sprites[j].dist_to_sprite
				> state->sprites[i].dist_to_sprite)
			{
				temp = state->sprites[i];
				state->sprites[i] = state->sprites[j];
				state->sprites[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	calc_dist_to_sprites(t_game_engine_state *state)
{
	int		i;
	double	delta_x;
	double	delta_y;

	i = 0;
	while (i < state->map->sprites_num)
	{
		delta_x = state->pos_x - state->sprites[i].x;
		delta_y = state->pos_y - state->sprites[i].y;
		state->sprites[i].dist_to_sprite = sqrt(delta_x * delta_x
				+ delta_y * delta_y);
		i++;
	}
}

void	calc_sprite_pos_on_screen(t_game_engine_state *state, t_sprite *sprite)
{
	double	delta_y;
	double	sprite_angle;
	double	corrected_dist;
	double	sprite_screen_x;
	double	sprite_dist_screen;

	delta_y = state->pos_y - sprite->y;
	sprite_angle = rad2deg(acos(delta_y / sprite->dist_to_sprite));
	if (state->pos_x > sprite->x)
		sprite_angle = -sprite_angle;
	sprite_angle = wrap_angle(state->direction - sprite_angle);
	corrected_dist = 0.0;
	sprite_screen_x = 0.0;
	if (sprite_angle < 90.0 || sprite_angle > 270.0)
	{
		sprite_dist_screen = state->dist_to_plane * tan(deg2rad(sprite_angle));
		sprite_screen_x = state->style->resolution.x / 2.0 - sprite_dist_screen;
		corrected_dist = cos(deg2rad(sprite_angle)) * sprite->dist_to_sprite;
		sprite->dist_to_sprite = corrected_dist;
		calc_sprite_draw_range(state, sprite, sprite_screen_x);
	}
	else
		sprite->dist_to_sprite = -1.0;
}

void	calc_sprite_draw_range(t_game_engine_state *state,
	t_sprite *sprite, double	sprite_screen_x)
{
	double	projected_sprite_width;

	sprite->projected_height = 1.0 / sprite->dist_to_sprite
		* state->dist_to_plane;
	sprite->draw_min_y = -sprite->projected_height / 2.0
		+ state->style->resolution.y / 2.0;
	sprite->draw_max_y = sprite->projected_height / 2.0
		+ state->style->resolution.y / 2.0;
	projected_sprite_width = sprite->projected_height
		* ((double)state->tex_info[TEXTURE_SPRITE].img_width
			/ (double)state->tex_info[TEXTURE_SPRITE].img_height);
	sprite->draw_min_x = -projected_sprite_width / 2.0 + sprite_screen_x;
	sprite->draw_max_x = projected_sprite_width / 2.0 + sprite_screen_x;
}
