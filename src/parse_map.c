/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:07 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/19 21:16:35 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>


#include "parse_map.h"

int		read_from_file(char *file)
{
	int		fd;
	int		success;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\nCan't open the file\n", 26);
		return (ERROR);
	}
	success = 1;
	while (success != 0)
	{
		success = get_next_line(fd, &line);
		if (success == -1)
		{
			write(1, "Error\nCan't read the content\n", 28);
			return (ERROR);
		}
		printf("%s\n", line); // replace with pushing the line to the linked list and counting num of lines
		free(line);
		line = NULL;
	}
	write(1, "EOF\n", 4);
	return (0);
}

int		parse_first_line(char *line, t_map *map)
{
	int i;

	if (map->height == 0)
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