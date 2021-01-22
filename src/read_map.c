/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:07 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/22 12:36:07 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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
	int			line_num;

	line = NULL;
	list_start = NULL;
	line_read = 1;
	line_num = 0;
	while (line_read != END_OF_FILE)
	{
		line_num++;
		line_read = get_next_line(fd, &line);
		if (line_read == -1)
		{
			return (report_error(line_num, "Error getting a line."));
		}
		if (!handle_lines_read(line, line_num))
		{
			free(line);
			return (ERROR);
		}
		if (!push_line_to_llist(list_start, line))
		{
			ft_lstclear(list_start, &free);
			return (ERROR);
		}
	}
	if (!parse_map(list_start))
	{
		return (ERROR);
	}
	ft_lstclear(list_start, &free);
	return (SUCCESS);
}

int		handle_lines_read(char *line, int line_num)
{
	int inside_map;

	inside_map = 0;
	if (is_empty_line(line))
	{
		if (!inside_map)
		{
			free(line);
			line = NULL;
			return (SUCCESS);
		}
		else
		{
			return (report_error(line_num, "Empty line inside the map"));
		}
	}
	else if (!parse_map_style_descriptor(line, line_num))
	{
		return (ERROR);
	}
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

/*
** If an identifier is found the line is parsed and line freed
** If the line is empty it is immediately freed
*/


int		report_error(int line_num, char *message)
{
	char line_num_to_alpha;

	line_num_to_alpha = ft_itoa(line_num);
	write(1, "Line ", 5);
	write(1, line_num_to_alpha, ft_strlen(line_num_to_alpha));
	write(1, ": ", 2);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	free(line_num_to_alpha);

	return(ERROR);
}

int		is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}