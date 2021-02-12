/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   style.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:22:15 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/12 11:04:27 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //remove!!
#include <stdlib.h>

#include "style.h"
#include "report_error.h"
#include "result.h"

void	init_map_style(t_style *style)
{
	int i;

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

int     validate_style(t_style *style)
{
	int i;

	if (style->resolution.x == INVALID_RESOLUTION
		|| style->resolution.y == INVALID_RESOLUTION)
	{
		return (report_error("Resolution element is invalid or missing."));
	}
	// else if (style->resolution.x < 200 || style->resolution.y < 200)
	// {
	// 	return (report_error("Window resolution must be at least 200"));
	// }
	if (style->ceiling_rgb == INVALID_COLOR || style->floor_rgb == INVALID_COLOR)
	{
		return (report_error("Floor or ceiling color element is missing."));
	}
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		if (style->textures[i] == NULL)
			return (report_error("A wall or sprite texture element is missing."));
		i++;
	}
	return (SUCCESS);
}

void	free_map_style(t_style *style)
{
	int i;

	i = 0;
	while (i < TEXTURE_COUNT)
	{
		free(style->textures[i]);
		style->textures[i] = NULL;
		i++;
	}
}


// remove this function before submossion!
void	debug_print_style(t_style *style)
{
	int i;

	printf("resolution.x:%d\n", style->resolution.x);
	printf("resolution.y:%d\n", style->resolution.y);
	printf("style->floor_rgb:%d\n", style->floor_rgb);
	printf("style->ceiling_rgb:%d\n", style->ceiling_rgb);
	i = 0;
	while (i < TEXTURE_COUNT)
	{
		printf("%s\n", style->textures[i]);

		i++;
	}

	// printf("style->no_texture:%s\n", style->no_texture);
	// printf("style->so_texture:%s\n", style->so_texture);
	// printf("style->ea_texture:%s\n", style->ea_texture);
	// printf("style->we_texture:%s\n", style->we_texture);
	// printf("style->sprite_texture:%s\n", style->sprite_texture);
}