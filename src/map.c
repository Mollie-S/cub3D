/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:06:50 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 14:28:53 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "map.h"

void	init_maze_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->start_direction = 0;
	map->start_pos_x = 0;
	map->start_pos_y = 0;
	map->fields = NULL;
}

void	free_maze_map(t_map *map)
{
	int y;

	y = 0;
	while (y < map->height)
	{
		free(map->fields[y]);
		y++;
	}
	free(map->fields);
}
