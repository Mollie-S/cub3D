/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 19:06:13 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/23 18:46:46 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

int		parse_map(t_list *list_start)
{
	t_map		map;

	map = (t_map){ 0, 0, 0, 0, 0 };
	if (!calculate_map_size(list_start, &map))
	{
		return (content_error());
	}
}

int		calculate_map_size(t_list *list_start, t_map *map)
{
	t_list	*line;
	int		line_len;

	if (list_start == NULL)
	{
		return (ERROR);
	}
	line = list_start;
	line_len = 0;
	while (line != NULL)
	{
		line_len = ft_strlen(line);
		if (line_len > map->width)
		{
			map->width = line_len;
		}
		map->height++;
		line = line->next;
	}
	return (SUCCESS);
}
