/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:06:50 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/08 23:46:34 by osamara       ########   odam.nl         */
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
