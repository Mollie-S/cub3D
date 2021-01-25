/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_header.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:57:38 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/25 22:49:23 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse_map_header.h"
#include "parse_resolution.h"
#include "parse_texture.h"
#include "parse_color.h"

int		parse_map_header(char *line, int line_num, int *is_inside_map)
{
	int result;

	result = is_empty_line(line);
	if (result != NOT_FOUND)
		return (result);
	result = parse_window_resolution(line, line_num);
	if (result != NOT_FOUND)
		return (result);
	result = parse_walls_textures(line, line_num);
	if (result != NOT_FOUND)
		return (result);
	result = parse_floor_ceiling_colors(line, line_num);
	if (result != NOT_FOUND)
		return (result);

	// else if (empty_line && is_inside_map)
	// 	return (report_error(line_num, "Empty line inside the map"));
	return (NOT_FOUND);
}
