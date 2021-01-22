/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_style.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:57:38 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/22 17:34:00 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../libft/include/libft.h"

#include "parse_map_style.h"
#include "style.h"
#include "window_resolution.h"

// longer way to initialize a structure
	// style.no_texture = NULL;
	// style.so_texture = NULL;
	// style.ea_texture = NULL;
	// style.we_texture = NULL;
	// style.sprite_texture = NULL;
	// style.floor_rgb = 0;
	// style.ceiling_rgb = 0;

int		parse_map_style_descriptor(char *line, int line_num)
{
	t_style style;

	style = (t_style){ 0, 0, 0, 0, 0, 0, 0 };
	if (has_identifier(line, "R "))
	{
		if (!parse_window_resolution(line, line_num))
			return (ERROR);
	}
	else if (has_identifier(line, "NO "))
		style.no_texture = parse_texture_path(line); // don't forget it can return NULL if malloc fails, so check for NULLs afterwards
	else if (has_identifier(line, "SO "))
		style.so_texture = parse_texture_path(line);
	else if (has_identifier(line, "EA "))
		style.ea_texture = parse_texture_path(line);
	else if (has_identifier(line, "WE "))
		style.we_texture = parse_texture_path(line);
	else if (has_identifier(line, "S "))
		style.sprite_texture = parse_texture_path(line);
	else if (has_identifier(line, "C "))
		style.ceiling_rgb = parse_color(line);
	else if (has_identifier(line, "F "))
		style.floor_rgb = parse_color(line);
	free(line);
	line = NULL;
	return (SUCCESS);
}

int		has_identifier(char *line, char *identifier)
{
	int	identifier_len;

	identifier_len = ft_strlen(identifier);
	return (ft_strncmp(line, identifier, identifier_len));
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
	texture_path = ft_strtrim(line + i, ' ');
	return (texture_path);
}

int		parse_color(char *line)
{
	int i;
	int	red;
	int green;
	int blue;
	int num_chars;
	// how to deal with the colors being 0,0,0 ? how to check that the color is valid?
	i = 0;
	red = -1;
	green = -1;
	blue = -1;
	while (line[i] != 0)
	{
		num_chars = 0;
		if ((line[i] = ' ' || ft_isdigit(line[i])) && red < 0)
		{
			red = ft_printf_atoi(line, &num_chars);
		}
		else if ((line[i] = ' ' || ft_isdigit(line[i])) && green < 0)
		{
			green = ft_printf_atoi(line + i, &num_chars);
		}
		else if ((line[i] = ' ' || ft_isdigit(line[i])) && blue < 0)
		{
			blue = ft_printf_atoi(line + i, &num_chars);
		}
		else if (line[i] = ',')
		{
			i++;
		}
		i += num_chars;
	}
	if (red >= 0 && green >= 0 && blue >= 0)
	{
		return (red << 16 | green << 8 | blue);
	}
	else
	{
		return (ERROR); // how to differentiate error and possible return value 0?
	}

}