/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:07 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/04 19:48:42 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"

#include "read_map.h"
#include "parsers/parse_map_header.h"
#include "parsers/parse_map.h"
#include "parsers/parsing_utils.h"
#include "report_error.h"
#include "result.h"
#include "utils.h"

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
	if (!validate_map(map, style))
	{
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
		if (gnl_result == -1)
			return (report_error_with_line(line_num, "Error getting a line."));
		if (handle_line(line, line_num, style, list_start) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

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
		inside_map = (result == NOT_FOUND);
	}
	if (inside_map)
	{
		if (!validate_style(style))
		return (report_error("Map description must precede the map content."));
		result = handle_map_line(line, line_num, list_start);
		if (result == ERROR)
		{
			ft_lstclear(list_start, &free);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	handle_map_line(char *line, int line_num, t_list **list_start)
{
	t_list	*new_node;
	if (*line == '\0')
	return (report_error_with_line(line_num, "Empty line is not allowed here."));
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
