/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 16:13:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/28 16:16:27 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_resolution.h"
#include "parsing_utils.h"
#include "report_error.h"
#include "utils.h"
#include "result.h"

#include <stddef.h>

int	parse_window_resolution(char *line, int line_num, t_resolution *resolution)
{
	int	identifier_len;

	identifier_len = 0;
	if (has_identifier(line, "R ", &identifier_len))
	{
		if (resolution->x != INVALID_RESOLUTION
			|| resolution->y != INVALID_RESOLUTION)
			return (report_error_with_line(line_num, "Repeating resolution."));
		if (!parse_resolution_components(line + identifier_len,
			line_num, resolution))
			return (ERROR);
	}
	else
		return (NOT_FOUND);
	return (SUCCESS);
}

int	parse_resolution_components(char *str_start, int line_num,
	t_resolution *resolution)
{
	char		**array;
	int			resolution_component;
	int			num_components;

	num_components = 2;
	array = split_into_components(str_start, ' ', num_components);
	if (array == NULL)
		return (report_error_with_line(line_num, "Unable to parse resolution"));
	resolution_component = 0;
	if (is_valid_component(array[0], &resolution_component))
		resolution->x = resolution_component;
	else
		return (report_error_with_line(line_num, "Invalid resolution x input"));
	if (is_valid_component(array[1], &resolution_component))
		resolution->y = resolution_component;
	else
		return (report_error_with_line(line_num, "Invalid resolution y input"));
	free_array_memory(array);
	return (SUCCESS);
}
