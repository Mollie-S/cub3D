/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:00:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 13:09:09 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../libft/include/libft.h"

#include "parse_texture.h"
#include "style.h"
#include "parsing_utils.h"

int		parse_walls_textures(char *line, int line_num, t_style *style)
{
	int 			identifier_len;

	identifier_len = 0;

	if (has_identifier(line, "NO ", &identifier_len))
		style->no_texture = parse_texture_path(line + identifier_len); // don't forget it can return NULL if malloc fails, so check for NULLs afterwards
	else if (has_identifier(line, "SO ", &identifier_len))
		style->so_texture = parse_texture_path(line + identifier_len);
	else if (has_identifier(line, "EA ", &identifier_len))
		style->ea_texture = parse_texture_path(line + identifier_len);
	else if (has_identifier(line, "WE ", &identifier_len))
		style->we_texture = parse_texture_path(line + identifier_len);
	else if (has_identifier(line, "S ", &identifier_len))
		style->sprite_texture = parse_texture_path(line + identifier_len);
	//check if all the paths are filled and return error if fails

	// remove!!
	write(1, &line_num, 1);
	return (SUCCESS);
}

char	*parse_texture_path(char *line)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (line[i] != ' ')
	{
		i++;
	}
	texture_path = ft_strtrim(line + i, " ");
	return (texture_path);
}