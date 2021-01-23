/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_header.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:57:38 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/23 14:02:12 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "../libft/include/libft.h"

#include "parse_map_header.h"
#include "style.h"
#include "window_resolution.h"
#include "report_error.h"


void		free_array_memory(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int		is_valid_component(const char *string, int *component)
{
	int		num_chars;
	int		accumulator;
	int		is_valid_component;
	char 	*trimmed_string;

	num_chars = 0;
	is_valid_component = 1;
	trimmed_string = ft_strtrim(string, " ");
	accumulator = ft_printf_atoi(trimmed_string, &num_chars);
	if (trimmed_string[num_chars] != 0)
	{
		is_valid_component = -1;
	}
	*component = accumulator;
	free(trimmed_string);
	return (is_valid_component);
}

static char		**split_into_components(char *line, char separator, int num_components)
{
	char	**array;
	int		i;

	array = ft_split(line, separator);
	if (array == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	if (i != num_components)
	{
		free_array_memory(array);
		return (NULL);
	}
	return (array);
}


int		has_identifier(char *line, char *identifier, int *identifier_len)
{
	size_t	len;
	int     is_identifier;

	len = ft_strlen(identifier);
	is_identifier = ft_strncmp(line, identifier, len);
	if (is_identifier != 0)
		return (FALSE);
	else
	{
		*identifier_len = (int)len;
		return (TRUE);
	}
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

// the function is too long and too many declarations
int		parse_color(char *line, unsigned int *color)
{
	char	**array;
	int		color_component;
	int		num_components;
	int		red;
	int		green; // can I use enum here?? how??
	int		blue;

	num_components = 3;
	array = split_into_components(line, ',', num_components);
	if (array == NULL)
		return (-1);
	color_component = 0;
	if (is_valid_component(array[0], &color_component)
		&& color_component >= 0 && color_component <= 255)
		red = color_component;
	else
		return (-1); // any way not to repeat error message?
	if (is_valid_component(array[1], &color_component)
		&& color_component >= 0 && color_component <= 255)
		green = color_component;
	else
		return (-1);
	if (is_valid_component(array[2], &color_component)
		&& color_component >= 0 && color_component <= 255)
		blue = color_component;
	else
		return (-1);
	free_array_memory(array);
	*color = red << 16 | green << 8 | blue;
	return (SUCCESS);
}


// rename the function!!
int		parse_window_resolution_1(char *str_start, int line_num)
{
	char					**array;
	int						resolution_component;
	int						num_components;
	t_window_resolution		resolution;

	num_components = 2;
	array = split_into_components(str_start, ' ', num_components);
	if (array == NULL)
		return (report_error(line_num, "Unable to parse display resolution"));
	resolution_component = 0;
	resolution = (t_window_resolution){ 0, 0 };
	if (is_valid_component(array[0], &resolution_component)
		&& resolution_component > 0 && resolution_component <= 7680) // do I use the largest resolution or monitor resolution???
		resolution.x = resolution_component;
	else
		return (report_error(line_num, "Invalid display resolution(x size)"));
	if (is_valid_component(array[1], &resolution_component)
		&& resolution_component > 0 && resolution_component <= 4320) // do I use the largest resolution currently available???
		resolution.y = resolution_component;
	else
		return (report_error(line_num, "Invalid display resolution(y size)"));
	free_array_memory(array);
	return (SUCCESS);
}


int		parse_floor_ceiling_colors(char *line, int line_num)
{
	int 			identifier_len;
	t_style 		style;
	unsigned int	color;
	int				is_valid_color;

	identifier_len = 0;
	style.floor_rgb = 0;
	style.ceiling_rgb = 0;
	color = 0;
	if (has_identifier(line, "C ", &identifier_len))
	{
		is_valid_color = parse_color(line + identifier_len, &color);
		if (is_valid_color < 0)
			style.ceiling_rgb = color;
		else
			return (report_error(line_num, "Invalid celing color."));
	}
	else if (has_identifier(line, "F ", &identifier_len))
	{
		is_valid_color = parse_color(line + identifier_len, &color);
		if (is_valid_color < 0)
			style.floor_rgb = color;
		else
			return (report_error(line_num, "Invalid floor color."));
	}
	return (SUCCESS);
}

int		parse_walls_textures(char *line, int line_num)
{
	int 			identifier_len;
	t_style 		style;

	identifier_len = 0;
	style.no_texture = NULL;
	style.so_texture = NULL;
	style.ea_texture = NULL;
	style.we_texture = NULL;
	style.sprite_texture = NULL;
	if (has_identifier(line, "NO ", &identifier_len))
		style.no_texture = parse_texture_path(line + identifier_len); // don't forget it can return NULL if malloc fails, so check for NULLs afterwards
	else if (has_identifier(line, "SO ", &identifier_len))
		style.so_texture = parse_texture_path(line + identifier_len);
	else if (has_identifier(line, "EA ", &identifier_len))
		style.ea_texture = parse_texture_path(line + identifier_len);
	else if (has_identifier(line, "WE ", &identifier_len))
		style.we_texture = parse_texture_path(line + identifier_len);
	else if (has_identifier(line, "S ", &identifier_len))
		style.sprite_texture = parse_texture_path(line + identifier_len);
	//check if all the paths are filled and return error if fails
	return (SUCCESS);
}

int		parse_window_resolution(char *line, int line_num)
{
	int identifier_len;

	identifier_len = 0;
	if (has_identifier(line, "R ", &identifier_len))
	{
		if (!parse_window_resolution_1(line + identifier_len, line_num))
			return (ERROR);
	}
	return (SUCCESS);
}

int		parse_map_header(char *line, int line_num)
{
	if (!parse_window_resolution(line, line_num))
		return (ERROR);
	if (!parse_walls_textures(line, line_num))
		return (ERROR);
	if (!parse_floor_ceiling_colors(line, line_num))
		return (ERROR);
	// uncomment if not chunks tests: 
//    free(line);  /
	line = NULL;
	return (SUCCESS);
}
