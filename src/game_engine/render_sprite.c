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

void	calc_sprite_offset(t_game_engine_state *state, t_sprite sprite)
{
	double	delta_y;
	double	sprite_angle;
	double	corrected_dist;
	double	plane_dist_to_sprite;
	double	sprite_screenX;

	delta_y = fabs(state->pos_y - sprite.y);
	sprite_angle = RAD2DEG(acos(delta_y / sprite.dist_to_sprite));
	plane_dist_to_sprite = 0.0;
	if (sprite_angle > -(FOV / 2) + state->direction && sprite_angle < (FOV / 2) + state->direction)
	{
		plane_dist_to_sprite = state->dist_to_plane / tan(DEG2RAD(fabs(state->direction - sprite_angle)));
		if (sprite_angle < state->direction)
			sprite_screenX = state->style->resolution.x / 2.0 - plane_dist_to_sprite;
		else
			sprite_screenX = state->style->resolution.x / 2.0 + plane_dist_to_sprite;
		corrected_dist = cos(DEG2RAD(fabs(state->direction - sprite_angle))) * sprite.dist_to_sprite;
		sprite.dist_to_sprite = corrected_dist; // comment off this for a while to see if it's distorted
	}
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
		calc_sprite_offset(state, state->sprites[i]);
}