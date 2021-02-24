/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 17:32:36 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/24 15:54:27 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "utils.h"

#include <stdlib.h>
#include <math.h>

void	init_sprite(t_sprite *sprite)
{
	sprite->x = 0.0;
	sprite->y = 0.0;
	sprite->dist_to_sprite = 0.0;
}

void	load_sprite_coordinates(t_game_engine_state *state)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
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
}
