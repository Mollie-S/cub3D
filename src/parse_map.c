/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 19:06:13 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/28 19:08:41 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "parse_map.h"
#include "report_error.h"

int		parse_map(t_list *list_start, t_map *map)
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
		return (report_error("Error reading the map"));
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
		return (report_error("Invalid map height or width."));
	}
	return (SUCCESS);
}

int		fill_map_fields(t_list *list_start, t_map *map)
{
	t_list		*current;
	size_t		fields_size;
	int			y;

	fields_size = map->height * map->width;
	map->fields = (char *)malloc(sizeof(char) * fields_size);
	if (map->fields == NULL)
		return (ERROR);
	ft_memset(map->fields, FIELD_BLACK_HOLE, fields_size);
	current = list_start;
	y = 0;
	while (current != NULL)
	{
		if (!define_start_position(current, map, y))
			return (ERROR);
		ft_memcpy(map->fields + y * map->width, current->content,
			ft_strlen((char*)current->content));
		current = current->next;
		y++;
	}
	return (SUCCESS);
}

int		define_start_position(t_list *current, t_map *map, int y)
{
	int		i;
	int		start_direction;
	char	*line;

	i = 0;
	start_direction = -1;
	line = (char*)current->content;
	while (line[i] != 0)
	{
		if (define_start_direction(line[i], &start_direction) != NOT_FOUND
			&& start_direction != -1)
		{
			if (map->start_direction == INVALID_START_DIRECTION)
			{
				map->start_direction = start_direction;
				map->start_pos_x = i;
				map->start_pos_y = y;
				line[i] = FIELD_EMPTY;
			}
			else
				return (report_error("Two or more characters define the start position."));
		}
		i++;
	}
	return (SUCCESS);
}

int		define_start_direction(char c, int *start_direction)
{
	if (c == 'N')
	{
		*start_direction = 0;
		return (SUCCESS);
	}
	else if (c == 'E')
	{
		*start_direction = 90;
		return (SUCCESS);
	}
	else if (c == 'S')
	{
		*start_direction = 180;
		return (SUCCESS);
	}
	else if (c == 'W')
	{
		*start_direction = 270;
		return (SUCCESS);
	}
	return (NOT_FOUND);
}
