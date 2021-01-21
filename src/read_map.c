/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:07 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/21 11:37:49 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "read_map.h"
#include "../get_next_line/get_next_line.h"
#include "parse_map.h"

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
	t_list 		*list_start;
	int			line_read;

	line = NULL;
	list_start = NULL;
	line_read = 1;
	while (line_read != END_OF_FILE)
	{
		line_read = get_next_line(fd, &line);
		if (line_read == -1)
		{
			return (content_error(line));
		}
		// check for all the identifiers first.
		// free line and assign it to null if it's not a map
		if (!push_line_to_llist(&list_start, line))
		{
			return (content_error(line));
		}
		if (!push_line_to_llist(&list_start, line))
		{
			return (content_error(line));
		}
	}
	if (!parse_map(list_start))
	{
		return (ERROR);
	}
	// clear list after parsing the map: 
// 	ft_lstclear(list_start, void (*del)(void*)) ???
	return (SUCCESS);
}

int		push_line_to_llist(t_list **list_start, char *line)
{
	t_list *new_node;

	new_node = ft_lstnew(line);
	if (!new_node)
	{
		return (content_error(line));
	}
	ft_lstadd_back(list_start, new_node);
	return (1);
}

int		content_error(char *line)
{
	write(1, "Can't read the content\n", 23);
	free(line);
	return(0);
}