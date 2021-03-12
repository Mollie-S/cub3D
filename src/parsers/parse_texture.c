/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:00:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/12 09:14:47 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_texture.h"
#include "parsing_utils.h"
#include "report_error.h"

#include "libft.h"

#include <unistd.h>
#include <fcntl.h>

static t_texture_identifier		g_tex_identifier[] = {
	{"NO ", TEXTURE_NO},
	{"SO ", TEXTURE_SO},
	{"EA ", TEXTURE_EA},
	{"WE ", TEXTURE_WE},
	{"S ", TEXTURE_SPRITE},
	{"SKY ", TEXTURE_SKYBOX}
};

int	parse_walls_textures(char *line, int line_num, t_style *style)
{
	int		identifier_len;
	int		i;

	while (*line == ' ')
		line++;
	identifier_len = 0;
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		if (has_identifier(line, g_tex_identifier[i].identifier,
				&identifier_len))
		{
			if (style->textures[g_tex_identifier[i].index] != NULL)
				return (report_error_with_line(line_num, "Repeating texture."));
			style->textures[g_tex_identifier[i].index] = ft_strtrim(line
					+ identifier_len, " \t");
			if (!validate_texture(style->textures[g_tex_identifier[i].index],
					line_num))
				return (ERROR);
			return (SUCCESS);
		}
		i++;
	}
	return (NOT_FOUND);
}

int	validate_texture(char *path_name, int line_num)
{
	int	fd;

	fd = open(path_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (report_error_with_line(line_num, "Texture path is invalid"));
	}
	close(fd);
	return (SUCCESS);
}
