/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:00:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/28 16:53:07 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../libft/include/libft.h"

#include "parse_texture.h"
#include "parsing_utils.h"
#include "report_error.h"

int		parse_walls_textures(char *line, int line_num, t_style *style)
{
	int 			identifier_len;

	identifier_len = 0;

	if (has_identifier(line, "NO ", &identifier_len))
	{
		if (style->no_texture != NULL)
			return (report_error_with_line(line_num, "Repeating North texture element."));
		style->no_texture = ft_strtrim(line + identifier_len, " ");
		return (SUCCESS);
	}
	if (has_identifier(line, "SO ", &identifier_len))
	{
		if (style->so_texture != NULL)
			return (report_error_with_line(line_num, "Repeating South texture element."));
		style->so_texture = ft_strtrim(line + identifier_len, " ");
		return (SUCCESS);
	}
	if (has_identifier(line, "EA ", &identifier_len))
	{
		if (style->ea_texture != NULL)
			return (report_error_with_line(line_num, "Repeating East texture element."));
		style->ea_texture = ft_strtrim(line + identifier_len, " ");
		return (SUCCESS);
	}
	if (has_identifier(line, "WE ", &identifier_len))
	{
		if (style->we_texture != NULL)
			return (report_error_with_line(line_num, "Repeating West texture element."));
		style->we_texture = ft_strtrim(line + identifier_len, " ");
		return (SUCCESS);
	}
	if (has_identifier(line, "S ", &identifier_len))
	{
		if (style->sprite_texture != NULL)
			return (report_error_with_line(line_num, "Repeating sprite texture element."));
		style->sprite_texture = ft_strtrim(line + identifier_len, " ");
		return (SUCCESS);
	}
	return (NOT_FOUND);
}
