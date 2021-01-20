/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:07 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/20 12:59:00 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "read_map.h"

int		open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Can't open the file\n", 20);
		return (ERROR);
	}
	if (!read_from_file(fd))
	{
		return (ERROR);
	}
	close(fd);
	return (0);
}

int		read_from_file(int fd)
{
	char 		*line;
	t_map		map;
	t_list 		*list_start;
	int			line_read;

	line = NULL;
	map = (t_map){ 0, 0, 0, 0, 0 };
	list_start = ft_lstnew(line); //create a new linked list
	if (!list_start)
	{
		return (ERROR);
	}
	line_read = 1;
	while (line_read != END_OF_FILE)
	{
		line_read = get_next_line(fd, &line);
		if (line_read == -1)
		{
			write(1, "Can't read the content\n", 23);
			return (ERROR);
		}
		push_line_to_llist(&list_start, line, &map); // pushing the line to the linked list and counting num of lines
		free(line);
		line = NULL;
		return (1);
	}
}

int		push_line_to_llist(t_list **list_start, char *line, t_map *map)
{
	t_list *new_node;

	new_node = ft_lstnew(line); //create a new linked list node
	if (!new_node)
	{
		return (ERROR);
	}
	ft_lstadd_back(list_start, new_node);
	map->height++;
	return (1);
}


// int		parse_first_line(char *line, t_map *map)
// {
// 	int i;

// 	if (map->height == 0)
// 	{
// 		i = 0;
// 		while (line[i] != 0)
// 		{
// 			if (line[i] != '1' || line[i] != ' ')
// 			{
// 				return (ERROR);
// 			}
// 			if (line[i] == ' ')
// 			{
// 				// do I need to keep track of those spaces in the future 
// 				//to make sure they are surrounded by '1'?
// 			}
// 			i++;
// 		}
// 	}
// 	map->num_lines++;
// }

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

// void	define_start_position(t_map * map, char *line)
// {
// 	int
// 		if
// }