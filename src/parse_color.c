/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:07:48 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 13:10:19 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse_color.h"
#include "style.h"
#include "parsing_utils.h"
#include "report_error.h"

int		parse_floor_ceiling_colors(char *line, int line_num, t_style *style)
{
	int					identifier_len;
	unsigned int		color;
	int					is_valid_color_component;

	identifier_len = 0;
	color = 0;
	if (has_identifier(line, "C ", &identifier_len))
	{
		is_valid_color_component = parse_color(line + identifier_len, &color);
		if (is_valid_color_component)
			style->ceiling_rgb = color;
		else
			return (report_error(line_num, "Invalid celing color."));
	}
	else if (has_identifier(line, "F ", &identifier_len))
	{
		is_valid_color_component = parse_color(line + identifier_len, &color);
		if (is_valid_color_component)
			style->floor_rgb = color;
		else
			return (report_error(line_num, "Invalid floor color."));
	}
	return (SUCCESS);
}

int		parse_color(char *line, unsigned int *color)
{
	char	**array;
	int		num_components;
	int		red;
	int		green; // can I use enum here?? how??
	int		blue;

	num_components = 3;
	array = split_into_components(line, ',', num_components);
	if (array == NULL)
		return (ERROR);
	if (!is_valid_color_component(array, &red, &green, &blue))
		return (ERROR);
	free_array_memory(array);
	*color = red << 16 | green << 8 | blue;
	return (SUCCESS);
}

int		is_valid_color_component(char **array, int *red, int *green, int *blue)
{
	int		color_component_value;

	color_component_value = 0;
	if (is_valid_component(array[0], &color_component_value)
		&& color_component_value >= 0 && color_component_value <= 255)
		*red = color_component_value;
	else
		return (ERROR); // any way not to repeat error message?
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
