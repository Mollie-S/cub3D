/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:07 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/19 15:48:35 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

int		parse_first_line(char *line, t_map *map)
{
	int i;

	if (map->num_lines == 0)
	{
		i = 0;
		while (line[i] != 0)
		{
			if (line[i] != '1' || line[i] != ' ')
			{
				return (ERROR);
			}
			if (line[i] == ' ')
			{
				// do I need to keep track of those spaces in the future 
				//to make sure they are surrounded by '1'?
			}
			i++;
		}
	}
	map->num_lines++;
}

// int		parse_map_line(char *line, t_map *map, int line_index)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] != '\n')
// 	{
// 		if (line[i] != map->empty && buffer[index] != map->obstacle)
// 			return (0);
// 		map->fields[line_index][index] = buffer[index];
// 		index++;
// 	}
// 	if (index != map->width)
// 		return (0);
// 	return (1);

void	define_start_position(t_map * map, char *line)
{
	int
		if
}