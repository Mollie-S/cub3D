/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_header.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:57:38 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/23 18:43:29 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parse_map_header.h"
#include "parse_resolution.h"
#include "parse_texture.h"
#include "parse_color.h"

int		parse_map_header(char *line, int line_num)
{
	if (!parse_window_resolution(line, line_num))
		return (ERROR);
	if (!parse_walls_textures(line, line_num))
		return (ERROR);
	if (!parse_floor_ceiling_colors(line, line_num))
		return (ERROR);
	// uncomment if not chunks tests: 
	free(line);
	line = NULL;
	return (SUCCESS);
}
