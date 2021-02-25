/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_sprite.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 14:26:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/24 14:29:31 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render_sprite.h"
#include "utils.h"
#include "game_loop.h"

#include <math.h>

double	calc_sprite_offset_x(t_game_engine_state *state, double sprite_angle)
{
	double	plane_dist_to_sprite;
	double	sprite_screen_x;

	plane_dist_to_sprite = state->dist_to_plane / tan(DEG2RAD(fabs(state->direction - sprite_angle)));
	if (sprite_angle < state->direction)
		sprite_screen_x = state->style->resolution.x / 2.0 - plane_dist_to_sprite;
	else
		sprite_screen_x = state->style->resolution.x / 2.0 + plane_dist_to_sprite;
	return (sprite_screen_x);
}

void	calc_sprite_draw_range(t_game_engine_state *state, t_sprite *sprite, double	sprite_screen_x)
{
	double	projected_sprite_height;
	double	projected_sprite_width;

	projected_sprite_height = 1.0 / sprite->dist_to_sprite * state->dist_to_plane;
	sprite->draw_min_y = -projected_sprite_height / 2.0 + state->style->resolution.y / 2.0 ;
	if (sprite->draw_min_y < 0) // does it prevent that half of the sprite is drawn?
		sprite->draw_min_y = 0;
	sprite->draw_max_y = projected_sprite_height / 2.0 + state->style->resolution.y / 2.0 ;
	if (sprite->draw_max_y > state->style->resolution.y)
		sprite->draw_max_y = state->style->resolution.y - 1;
	projected_sprite_width = projected_sprite_height;
	sprite->draw_min_x = -projected_sprite_width / 2.0 + sprite_screen_x;
	if (sprite->draw_min_x < 0)
		sprite->draw_min_x = 0;
	sprite->draw_max_x = projected_sprite_width / 2.0 + sprite_screen_x;
	if (sprite->draw_max_x > state->style->resolution.x)
		sprite->draw_max_x = state->style->resolution.x - 1;
}

void	calc_sprite_pos_on_screen(t_game_engine_state *state, t_sprite sprite)
{
	double	delta_y;
	double	sprite_angle;
	double	corrected_dist;
	double	sprite_screen_x;

	delta_y = fabs(state->pos_y - sprite.y);
	sprite_angle = RAD2DEG(acos(delta_y / sprite.dist_to_sprite));
	corrected_dist = 0.0;
	sprite_screen_x = 0.0;
	if (sprite_angle > -90.0 + state->direction && sprite_angle < 90.0 + state->direction) // removed sprites begind me
	{
		sprite_screen_x = calc_sprite_offset_x(state, sprite_angle);
		corrected_dist = cos(DEG2RAD(fabs(state->direction - sprite_angle))) * sprite.dist_to_sprite;
		sprite.dist_to_sprite = corrected_dist; // comment off this for a while to see if it's distorted
		calc_sprite_draw_range(state, &sprite, sprite_screen_x);
	}
	else
		sprite.dist_to_sprite = -1.0;
}

void	calc_dist_to_sprites(t_game_engine_state *state, t_sprite *sprites)
{
	int	i;

	i = 0;
	while (i < state->map->sprites_num)
	{

		sprites[i].dist_to_sprite = sqrt(pow(fabs(state->pos_x - sprites[i].x), 2.0)
			+ pow(fabs(state->pos_y - sprites[i].y), 2.0));
		i++;
	}
}

void	sort_sprites(t_game_engine_state *state)
{
	int 		i;
	int 		j;
	t_sprite	temp;

	i = 0;
	calc_dist_to_sprites(state, state->sprites);
	while (i < state->map->sprites_num)
	{
		j = i + 1;
		while (j < state->map->sprites_num)
		{
			if (state->sprites[j].dist_to_sprite > state->sprites[i].dist_to_sprite)
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


void	render_sprites(t_game_engine_state *state)
{
	int i;

	sort_sprites(state);
	// in a loop for all the sprites: 
	i = 0;
	while (i < state->map->sprites_num)
		calc_sprite_pos_on_screen(state, state->sprites[i]);
}