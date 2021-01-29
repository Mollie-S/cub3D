/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:06:50 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/28 21:20:12 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // remove the header!!!
#include <stdlib.h>

#include "map.h"
#include "report_error.h"
#include "result.h"

void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->start_direction = -1;
	map->start_pos_x = -1;
	map->start_pos_y = -1;
	map->fields = NULL;
}

int		validate_map(t_map *map)
{
	if (map->fields == NULL)
		return (report_error("Invalid map."));
	if (map->start_direction == INVALID_START_DIRECTION)
		return (report_error("Player's start position is not set"));


	return (SUCCESS);
}

void	free_map(t_map *map)
{
	free(map->fields);
	// do I set other var to 0?  why?
}

// remove this function before submossion!
void	debug_print_map(t_map *map)
{
	unsigned int y = 0;
	printf("map->height:%lu\n", map->height);
	printf("map->width:%lu\n", map->width);
	printf("map->start_direction:%d\n", map->start_direction);
	printf("map->start_pos_x:%d\n", map->start_pos_x);
	printf("map->start_pos_y:%d\n", map->start_pos_y);
	while (y < map->height)
	{
		unsigned int x = 0;
		while (x < map->width)
		{
			printf("%c", map->fields[y * map->width + x]);
			x++;
		}
		printf("\n");
		y++;
	}

}
