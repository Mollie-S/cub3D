/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_header.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:57:38 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 23:13:15 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map_header.h"
#include "parse_resolution.h"
#include "parse_texture.h"
#include "parse_color.h"
#include "parsing_utils.h"
#include "result.h"

#include <stdlib.h>

int	parse_map_header(char *line, int line_num, t_style *style)
{
	int	result;

	if (is_empty_line(line))
		return (SUCCESS);
	result = parse_window_resolution(line, line_num, &style->resolution);
	if (result != NOT_FOUND)
		return (result);
	result = parse_walls_textures(line, line_num, style);
	if (result != NOT_FOUND)
		return (result);
	result = parse_colors(line, line_num, style);
	if (result != NOT_FOUND)
		return (result);
	return (NOT_FOUND);
}
