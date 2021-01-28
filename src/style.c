/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   style.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:22:15 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/28 18:07:51 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //remove!!
#include <stdlib.h>

#include "style.h"
#include "report_error.h"
#include "result.h"

void	init_map_style(t_style *style)
{

	style->start_resolution.x = -1;
	style->start_resolution.y = -1;
	style->no_texture = NULL;
	style->so_texture = NULL;
	style->ea_texture = NULL;
	style->we_texture = NULL;
	style->sprite_texture = NULL;
	style->floor_rgb = INVALID_COLOR;
	style->ceiling_rgb = INVALID_COLOR;
}

int     validate_style(t_style *style)
{
	if (style->start_resolution.x == INVALID_RESOLUTION
		|| style->start_resolution.y == INVALID_RESOLUTION)
	{
		return (report_error("Resolution element is invalid or missing."));
	}
	else if (style->start_resolution.x < 200 || style->start_resolution.y < 200)
	{
		return (report_error("Window resolution must be at least 200"));
	}
	// do I check for the screen_szie and adjust x and y here?

	if (style->ceiling_rgb == INVALID_COLOR || style->floor_rgb == INVALID_COLOR)
	{
		return (report_error("Floor or ceiling color element is missing."));
	}
	if (style->no_texture == NULL || style->so_texture == NULL
		|| style->ea_texture == NULL || style->we_texture == NULL
		|| style->sprite_texture == NULL)
	{
		return (report_error("A wall or sprite texture element is missing."));
	}
	return (SUCCESS);
}

void	free_map_style(t_style *style)
{
	free(style->no_texture);
	free(style->so_texture);
	free(style->ea_texture);
	free(style->we_texture);
	free(style->sprite_texture);
}
