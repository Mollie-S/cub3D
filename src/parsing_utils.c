/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 16:52:28 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 11:16:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../libft/include/libft.h"

#include "parsing_utils.h"
#include "report_error.h"

int		are_valid_characters(char *line, int line_num)
{
	char 	*chars_in_map;
	int		i;
	int		j;

	chars_in_map = "012NSEW";
	i = 0;
	j = 0;
	while (line[i] != 0)
	{
		while (chars_in_map[j])
		{
			if (line[i] != chars_in_map[j])
			{
				return (report_error(line_num, "Invalid characters."));
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int		is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
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
		is_valid_component = 0;
	}
	*component = accumulator;
	free(trimmed_string);
	return (is_valid_component);
}

char		**split_into_components(char *line, char separator, int num_components)
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
