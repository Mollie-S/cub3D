/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_style.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:57:38 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/21 12:57:41 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "parse_map_style.h"
#include "style.h"

int		parse_map_style_descriptor(char *line)
{
	int	i;
	t_style style;

	i = 0;
	style.no_texture = NULL;
	style.so_texture = NULL;
	style.ea_texture = NULL;
	style.we_texture = NULL;
	style.sprite_texture = NULL;
	while (line[i] != 0)
	{

	}

}