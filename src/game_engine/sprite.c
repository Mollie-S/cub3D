/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 17:32:36 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/28 09:11:20 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "utils.h"
#include "report_error.h"
#include "result.h"

#include <stdlib.h>
#include <math.h>

void	init_sprite(t_game_engine_state *state, t_sprite *sprite)
{
	sprite->x = 0.0;
	sprite->y = 0.0;
	sprite->dist_to_sprite = 0.0;
	sprite->sprite_tex_info = &state->tex_info[TEXTURE_SPRITE];
	sprite->draw_min_x = 0.0;
	sprite->draw_max_x = 0.0;
	sprite->draw_min_y = 0.0;
	sprite->draw_max_y = 0.0;
	sprite->projected_height = 0.0;
}

int	load_sprite_coordinates(t_game_engine_state *state)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	state->sprites = malloc(sizeof(t_sprite) * state->map->sprites_num);
	if (state->sprites == NULL)
	{
		return (report_error("Error allocating memory for sprites."));
	}
	while (count < state->map->sprites_num)
	{
		if (state->map->fields[i] == FIELD_SPRITE)
		{
			state->sprites[count].x = (i % state->map->width) + 0.5;
			state->sprites[count].y = (i / state->map->width) + 0.5;
			count++;
		}
		i++;
	}
	return (SUCCESS);
}
