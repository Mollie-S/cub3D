/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 16:13:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/27 21:02:26 by osamara       ########   odam.nl         */
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
		return (report_error(line_num, "Unable to parse window resolution"));
	resolution_component = 0;
	if (is_valid_component(array[0], &resolution_component))
		start_resolution.x = resolution_component;
	else
		return (report_error(line_num, "Invalid resolution input(x size)"));
	if (is_valid_component(array[1], &resolution_component))
		start_resolution.y = resolution_component;
	else
		return (report_error(line_num, "Invalid resolution input(y size)"));
	free_array_memory(array);
	return (SUCCESS);
}

// to add to validation:
//
// 		&& resolution_component > 0 && resolution_component <= (resolution of the screen))
// compare with the current resolution of display