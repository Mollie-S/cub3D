/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 16:13:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/28 17:55:02 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "parse_resolution.h"
#include "parsing_utils.h"
#include "report_error.h"

int		parse_window_resolution(char *line, int line_num, t_resolution *start_resolution)
{
	int identifier_len;

	identifier_len = 0;
	if (has_identifier(line, "R ", &identifier_len))
	{
		if (start_resolution->x != INVALID_RESOLUTION
			|| start_resolution->y != INVALID_RESOLUTION)
			return (report_error_with_line(line_num, "Repeating resolution element."));
		if (!parse_resolution_components(line + identifier_len, line_num, start_resolution))
			return (ERROR);
	}
	else
		return (NOT_FOUND);
	return (SUCCESS);
}

int		parse_resolution_components(char *str_start, int line_num, t_resolution *start_resolution)
{
	char		**array;
	int			resolution_component;
	int			num_components;

	num_components = 2;
	array = split_into_components(str_start, ' ', num_components);
	if (array == NULL)
		return (report_error_with_line(line_num, "Unable to parse window resolution"));
	resolution_component = 0;
	if (is_valid_component(array[0], &resolution_component))
		start_resolution->x = resolution_component;
	else
		return (report_error_with_line(line_num, "Invalid resolution input(x size)"));
	if (is_valid_component(array[1], &resolution_component))
		start_resolution->y = resolution_component;
	else
		return (report_error_with_line(line_num, "Invalid resolution input(y size)"));
	free_array_memory(array);
	return (SUCCESS);
}
