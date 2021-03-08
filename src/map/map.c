/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:06:50 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/08 14:14:33 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#include <stdlib.h>

void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->start_direction = -1;
	map->start_pos_x = -1;
	map->start_pos_y = -1;
	map->fields = NULL;
	map->sprites_num = 0;
}

void	free_map(t_map *map)
{
	free(map->fields);
	map->fields = NULL;
}

int	count_sprites(t_map *map)
{
	int	map_size;
	int	sprites_num;
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
