/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:07 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/30 10:11:00 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "../get_next_line/get_next_line.h"

#include "read_map.h"
#include "parse_map_header.h"
#include "parse_map.h"
#include "parsing_utils.h"
#include "report_error.h"
#include "result.h"


int		parse_cub_map(char *file, t_style *style, t_map *map)
{
	t_list 		*list_start;

	list_start = NULL;

	if (!load_map_from_file(file, style, &list_start))
		return (ERROR);
	if (!parse_map(list_start, map))
		return (ERROR);
	ft_lstclear(&list_start, &free);
	if (!validate_style(style) || !validate_map(map))
	{
		free_map_style(style);
		free_map(map);
		return (ERROR);
	}
	return (SUCCESS);
}

int		load_map_from_file(char *file, t_style *style, t_list **list_start)
{
	char 	*line;
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
		return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}

int		read_from_file(int fd, char *line, t_style *style, t_list **list_start)
{
	int		gnl_result;
	int 	inside_map;
	int		line_num;
	int		result;

	gnl_result = 1;
	line_num = 0;
	inside_map = 0;
	result = 0;
	while (gnl_result != END_OF_FILE)
	{
		line_num++;
		gnl_result = get_next_line(fd, &line);
		if (gnl_result == -1)
			return (report_error_with_line(line_num, "Error getting a line."));
		if (!inside_map)
		{
			result = parse_map_header(line, line_num, style);
			if (result != NOT_FOUND)
				free(line);
			if (result == ERROR)
				return (ERROR);
			// return (report_error_with_line(line_num, "Invalid map input."));
			inside_map = (result == NOT_FOUND);
		}
		if (inside_map)
		{
			result = parse_map_line(line, line_num, list_start);
			if (result == ERROR)
			{
				ft_lstclear(list_start, &free);
				return (ERROR);
			}
		}
	}
	return (SUCCESS);
}

int		parse_map_line(char *line, int line_num, t_list **list_start)
{
	if (!are_valid_characters(line, line_num))
		return (ERROR);
	else
		return (push_line_to_llist(list_start, line, line_num));
}

int		push_line_to_llist(t_list **list_start, char *line, int line_num)
{
	t_list *new_node;

	new_node = ft_lstnew(line);
	if (!new_node)
	{
		return (report_error_with_line(line_num, "Error allocating memory for a line."));
	}
	ft_lstadd_back(list_start, new_node);
	return (SUCCESS);
}
