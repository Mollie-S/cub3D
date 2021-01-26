/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   style.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:22:15 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 13:03:09 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "style.h"

void	init_map_style(t_style *style)
{
	t_resolution start_resolution;

	start_resolution.x = 0;
	start_resolution.y = 0;
	style->no_texture = NULL;
	style->so_texture = NULL;
	style->ea_texture = NULL;
	style->we_texture = NULL;
	style->sprite_texture = NULL;
	style->floor_rgb = 0;
	style->ceiling_rgb = 0;
}

void	free_map_style(t_style *style)
{
	free(style->no_texture);
	free(style->so_texture);
	free(style->ea_texture);
	free(style->we_texture);
	free(style->sprite_texture);
}
