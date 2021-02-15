/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 17:32:36 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/15 11:57:26 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "utils.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h> //remove after debugging


void	init_sprite(t_sprite *sprite)
{
	sprite->x = 0.0;
	sprite->y = 0.0;
}

void	load_sprites(t_game_engine_state *state)
{
	int	sprites_num;

	sprites_num = count_sprites(state->map);
	if (sprites_num > 0)
	{
		state->sprites = malloc(sizeof(t_sprite) * sprites_num);
		load_sprite_coordinates(state, sprites_num);
		sort_sprites(state, sprites_num);
	}

}

int	count_sprites(t_map *map)  // I don't need to calc sprites every time here, right?
{
	int	map_size;
	int sprites_num;
	int	i;

	map_size = map->height * map->width;
	i = 0;
	sprites_num = 0;
	while (i < map_size)
	{
		if (map->fields[i] == FIELD_SPRITE)
		{
			sprites_num++;
		}
		i++;
	}
	return (sprites_num);
}

void	load_sprite_coordinates(t_game_engine_state *state, int sprites_num)
{
	int	i;
	int	count;
	i = 0;
	count = 0;
	while (count < sprites_num)
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

void	calc_dist_to_sprites(t_game_engine_state *state, int sprites_num, double *sprite_dist)
{
	int	i;

	i = 0;
	while (i < sprites_num)
	{
		sprite_dist[i] = pow(fabs(state->pos_x - state->sprites[i].x), 2.0)
			+ pow(fabs(state->pos_y - state->sprites[i].y), 2.0);
		i++;
	}
}

void	sort_sprites(t_game_engine_state *state, int sprites_num)
{
	double		sprite_dist[sprites_num];
	int 		i;
	int 		j;
	t_sprite	temp;

	i = 0;
	calc_dist_to_sprites(state, sprites_num, sprite_dist);
	while (i < sprites_num)
	{
		j = i + 1;
		while (j < sprites_num)
		{
			if (sprite_dist[j] > sprite_dist[i])
			{
				swap(&sprite_dist[i], &sprite_dist[j]);
				// swap_sprites(&state->sprites, i, j);  how to make a separate function for struct swaps?
				temp = state->sprites[i];
				state->sprites[i] = state->sprites[j];
				state->sprites[j] = temp;
			}
			j++;
		}
		i++;
	}
}