/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   style.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:22:15 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 18:37:02 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include "report_error.h"
#include "result.h"

#include <stdlib.h>

void	init_map_style(t_style *style)
{
	int	i;

	style->resolution.x = -1;
	style->resolution.y = -1;
	style->floor_rgb = INVALID_COLOR;
	style->ceiling_rgb = INVALID_COLOR;
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		style->textures[i] = NULL;
		i++;
	}
}

int	validate_style(t_style *style)
{
	int	i;

	if (style->resolution.x == INVALID_RESOLUTION
		|| style->resolution.y == INVALID_RESOLUTION)
		return (report_error("Resolution element is invalid or missing."));
	else if (style->resolution.x < 200 || style->resolution.y < 20)
		return (report_error("Window resolution must be at least 200"));
	if (style->ceiling_rgb == INVALID_COLOR
		|| style->floor_rgb == INVALID_COLOR)
		return (report_error("Floor or ceiling color element is missing."));
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		if (BONUS && style->textures[TEXTURE_SKYBOX] == NULL)
			return (report_error("The skybox texture for bonus is missing."));
		if (i != TEXTURE_SKYBOX && style->textures[i] == NULL)
		{
			return (report_error("A wall or sprite texture is missing."));
		}
		i++;
	}
	return (SUCCESS);
}

void	free_map_style(t_style *style)
{
	int	i;

	i = 0;
	while (i < TEXTURE_COUNT)
	{
		free(style->textures[i]);
		style->textures[i] = NULL;
		i++;
	}
}
