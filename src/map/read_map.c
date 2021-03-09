/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:07 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/08 21:41:44 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "parsers/parse_map_header.h"
#include "parsers/parse_map.h"
#include "parsers/parsing_utils.h"
#include "report_error.h"
#include "result.h"
#include "validate_map.h"

#include "get_next_line.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	parse_cub_map(char *file, t_style *style, t_map *map)
{
	t_list	*list_start;

	list_start = NULL;
	if (!load_map_from_file(file, style, &list_start))
	{
		free_map_style(style);
		return (ERROR);
	}
	if (!parse_map(list_start, map))
		return (ERROR);
	ft_lstclear(&list_start, &free);
	if (!validate_style(style) || !validate_map(map, style))
	{
		free_map_style(style);
		free_map(map);
		return (ERROR);
	}
	return (SUCCESS);
}

int	load_map_from_file(char *file, t_style *style, t_list **list_start)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Can't open the file");
		return (ERROR);
	}
	if (!read_from_file(fd, line, style, list_start))
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}

int	read_from_file(int fd, char *line, t_style *style, t_list **list_start)
{
	int	gnl_result;
	int	line_num;

	gnl_result = 1;
	line_num = 0;
	while (gnl_result != END_OF_FILE)
	{
		line_num++;
		gnl_result = get_next_line(fd, &line);
		if (gnl_result == END_OF_FILE && line[0] == 0)
			break ;
		if (gnl_result == -1)
			return (report_error_with_line(line_num, "Error getting a line."));
		if (handle_line(line, line_num, style, list_start) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

/*
** As the subject says
** that the map content must be the last element:
**
** if the line was not found inside the map header(descriptor)
** I assume that the map contents(the maze itself) has started
** and handle the line as the map content from now.
*/

int	handle_line(char *line, int line_num, t_style *style, t_list **list_start)
{
	static int	inside_map;
	int			result;

	result = 0;
	if (!inside_map)
	{
		result = parse_map_header(line, line_num, style);
		if (result != NOT_FOUND)
			free(line);
		if (result == ERROR)
			return (ERROR);
		if (result == NOT_FOUND)
			inside_map = TRUE;
	}
	if (inside_map)
	{
		result = handle_map_content_line(line, line_num, list_start);
		if (result == ERROR)
		{
			ft_lstclear(list_start, &free);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	handle_map_content_line(char *line, int line_num, t_list **list_start)
{
	t_list	*new_node;

	if (*line == '\0')
		return (report_error_with_line(line_num,
				"Empty line is not allowed here."));
	if (!are_valid_characters(line, line_num))
		return (ERROR);
	else
		new_node = ft_lstnew(line);
	if (!new_node)
	{
		return (report_error_with_line(line_num,
				"Error allocating memory for a line."));
	}
	ft_lstadd_back(list_start, new_node);
	return (SUCCESS);
}
