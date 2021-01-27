/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 19:06:13 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/27 15:34:38 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "parse_map.h"

int		parse_maze_map(t_list *list_start, t_map *map)
{
	if (!calculate_map_size(list_start, map))
	{
		return (ERROR);
	}
	if (!fill_map_fields(list_start, map))
	{
		return (ERROR);
	}
	return (SUCCESS);
}

int		calculate_map_size(t_list *list_start, t_map *map)
{
	t_list		*current;
	size_t		line_len;

	if (list_start == NULL)
	{
		perror("Error reading the map"); // should I  be more specific?
		return (ERROR);
	}
	current = list_start;
	line_len = 0;
	while (current != NULL)
	{
		line_len = ft_strlen(current->content);
		if (line_len > map->width)
			map->width = line_len;
		map->height++;
		current = current->next;
	}
	if (map->height < 3 || map->width < 3)
	{
		perror("Invalid map height or width.\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int        fill_map_fields(t_list * list_start, t_map * map)
{
	t_list	    *current;
	char 	    *line;
	size_t		fields_size;
	int		    y;

	fields_size = map->height * map->width;
	map->fields = (char *)malloc(sizeof(char) * fields_size);
	if (map->fields == NULL)
		return (ERROR);
	ft_memset(map->fields, FIELD_BLACK_HOLE, fields_size);
	current = list_start;
	line = (char*)current->content;
	y = 0;
	while (current != NULL)
	{
		if (!check_start_position(line, map, y))
			return (ERROR);
		ft_memcpy(map->fields + y * map->width, line, ft_strlen(line));
		current = current->next;
		y++;
	}
	return (SUCCESS);
}

int		check_start_position(char *line, t_map *map, int y)
{
	int 	i;
	int		start_direction;

	i = 0;
	start_direction = -1;
	while (line[i] != 0)
	{
		set_start_direction(line[i], &start_direction);
		if (start_direction != -1)
		{
			if (map->start_direction != -1)
			{
				map->start_direction = start_direction;
				map->start_pos_x = i;
				map->start_pos_y = y;
				line[i] = FIELD_EMPTY;
			}
			else
			{
				perror("Player's start position is not unique.");
				return (ERROR);
			}
		}
		i++;
	}
	return (SUCCESS);
}

void		set_start_direction(char c, int *start_direction)
{
	if (c == 'N')
		*start_direction = 0;
	else if (c == 'E')
		*start_direction = 90;
	else if (c == 'S')
		*start_direction = 180;
	else if (c == 'W')
		*start_direction = 270;

}