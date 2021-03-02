/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:07:48 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 23:17:35 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_color.h"
#include "parsing_utils.h"
#include "report_error.h"
#include "utils.h"

#include <stdlib.h>

int	parse_colors(char *line, int line_num, t_style *style)
{
	int					identifier_len;

	identifier_len = 0;
	if (has_identifier(line, "C ", &identifier_len))
	{
		return (get_color_value(&style->ceiling_rgb,
				line, line_num, identifier_len));
	}
	if (has_identifier(line, "F ", &identifier_len))
	{
		return (get_color_value(&style->floor_rgb, line,
				line_num, identifier_len));
	}
	return (NOT_FOUND);
}

int	get_color_value(unsigned int *rgb, char *line, int line_num,
	int identifier_len)
{
	unsigned int		color;
	int					is_valid_color_component;

	color = 0;
	if (*rgb != INVALID_COLOR)
		return (report_error_with_line(line_num, "Repeating color."));
	is_valid_color_component = validate_color(line + identifier_len, &color);
	if (is_valid_color_component)
		*rgb = color;
	else
	{
		return (report_error_with_line(line_num,
				"Invalid floor or ceiling color."));
	}
	return (SUCCESS);
}

int	validate_color(char *line, unsigned int *color)
{
	char	**array;
	int		num_components;
	int		red;
	int		green;
	int		blue;

	num_components = 3;
	array = split_into_components(line, ',', num_components);
	if (array == NULL)
		return (ERROR);
	if (!is_valid_color_component(array, &red, &green, &blue))
		return (ERROR);
	*color = red << 16 | green << 8 | blue;
	free_array_memory(array);
	return (SUCCESS);
}

int	is_valid_color_component(char **array, int *red, int *green, int *blue)
{
	int		color_component_value;

	color_component_value = 0;
	if (is_valid_component(array[0], &color_component_value)
		&& color_component_value >= 0 && color_component_value <= 255)
		*red = color_component_value;
	else
		return (ERROR);
	if (is_valid_component(array[1], &color_component_value)
		&& color_component_value >= 0 && color_component_value <= 255)
		*green = color_component_value;
	else
		return (ERROR);
	if (is_valid_component(array[2], &color_component_value)
		&& color_component_value >= 0 && color_component_value <= 255)
		*blue = color_component_value;
	else
		return (ERROR);
	return (SUCCESS);
}
