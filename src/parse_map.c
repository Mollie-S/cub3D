/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 19:06:13 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 13:17:15 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "parse_map.h"

int		parse_maze_map(t_list *list_start, t_map *map)
{

	if (!calculate_map_size(list_start, map))
	{
		return (ERROR);
	}
	return (SUCCESS);
}

int		calculate_map_size(t_list *list_start, t_map *map)
{
	t_list		*line;
	size_t		line_len;

	if (list_start == NULL)
	{
		perror("Error reading the map");
		return (ERROR);
	}
	line = list_start;
	line_len = 0;
	while (line != NULL)
	{
		line_len = ft_strlen(line->content);
		if (line_len > map->width)
		{
			map->width = line_len;
		}
		map->height++;
		line = line->next;
	}
	if (map->height < 3 || map->width < 3)
	{
		perror("Invalid map height or width.\n");
		return (ERROR);
	}
	return (SUCCESS);
}
