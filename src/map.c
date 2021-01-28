/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:06:50 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/28 15:24:37 by osamara       ########   odam.nl         */
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
	map->start_pos_x = 0;
	map->start_pos_y = 0;
	map->fields = NULL;
}

int		validate_map(t_map *map)
{
	if (map->fields == NULL)
		return (report_error("Invalid map."));
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
	int y = 0;
	while (y < map->height)
	{
		int x = 0;
		while (x < map->width)
		{
			printf("%c", map->fields[y * map->width + x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
