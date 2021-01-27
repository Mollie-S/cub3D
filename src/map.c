/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:06:50 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 22:15:39 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "map.h"

void	init_maze_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->start_direction = -1;
	map->start_pos_x = 0;
	map->start_pos_y = 0;
	map->fields = NULL;
}

void	free_maze_map(t_map *map)
{
	free(map->fields);
	// do I set other var to 0?  why?
}
