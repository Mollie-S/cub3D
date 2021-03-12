/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 13:43:33 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/12 00:58:03 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validate_map.h"
#include "report_error.h"
#include "result.h"
#include "utils.h"

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

int	validate_map(t_map *map, t_style *style)
{
	char	*check_array;

	if (map->start_direction == INVALID_START_DIRECTION)
		return (report_error("Player's start position is not set"));
	if (map->fields == NULL)
		return (report_error("Invalid map."));
	check_array = ft_calloc(map->height * map->width, 1);
	if (!check_array)
		return (report_error("Error allocating memory for map validation."));
	if (!ft_floodfill(map->start_pos_x, map->start_pos_y, check_array, map))
		return (ERROR);
	check_unreachable_space(map, check_array);
	free(check_array);
	check_array = NULL;
	map->sprites_num = count_sprites(map);
	if (map->sprites_num == 0 && style->textures[TEXTURE_SPRITE] != NULL)
		return (report_error("The map contains no accessible sprites"));
	return (SUCCESS);
}

int	ft_floodfill(size_t x, size_t y, char *check_array, t_map *map)
{
	size_t	field_index;

	field_index = map->width * y + x;
	if (map->fields[field_index] == FIELD_BLACK_HOLE)
		return (report_error("The map is not surrounded by walls (hole)"));
	if (map->fields[field_index] != FIELD_WALL && check_array[field_index] == 0)
	{
		if (x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
			return (report_error("The map is not surrounded by walls (edge)"));
		check_array[field_index] = 1;
		if (!ft_floodfill(x + 1, y, check_array, map)
			|| !ft_floodfill(x - 1, y, check_array, map)
			|| !ft_floodfill(x, y + 1, check_array, map)
			|| !ft_floodfill(x, y - 1, check_array, map)
			|| !ft_floodfill(x + 1, y + 1, check_array, map)
			|| !ft_floodfill(x + 1, y - 1, check_array, map)
			|| !ft_floodfill(x - 1, y + 1, check_array, map)
			|| !ft_floodfill(x - 1, y - 1, check_array, map))
			return (ERROR);
	}
	return (SUCCESS);
}

void	check_unreachable_space(t_map *map, char *check_array)
{
	int	map_size;
	int	i;

	map_size = map->height * map->width;
	i = 0;
	while (i < map_size)
	{
		if (check_array[i] == 0 && map->fields[i] != FIELD_WALL
			&& map->fields[i] != FIELD_BLACK_HOLE)
		{
			printf(ANSI_COLOR_YELLOW "Warning:\n" ANSI_COLOR_RESET);
			printf(ANSI_BOLD_BLACK "The map has the space that the player "
				"is unable to access\n\n" ANSI_COLOR_RESET);
			print_map_with_warning(map, check_array);
			return ;
		}
		i++;
	}
}

void	print_map_with_warning(t_map *map, char *check_array)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (check_array[y * map->width + x] == 1)
				printf("%c", map->fields[y * map->width + x]);
			else if (check_array[y * map->width + x] == 0
				&& (map->fields[y * map->width + x] == FIELD_BLACK_HOLE
					|| map->fields[y * map->width + x] == FIELD_WALL))
				printf("%c", map->fields[y * map->width + x]);
			else
				printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET,
					map->fields[y * map->width + x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

int	count_sprites(t_map *map)
{
	int	map_size;
	int	sprites_num;
	int	i;

	map_size = map->height * map->width;
	i = 0;
	sprites_num = 0;
	while (i < map_size)
	{
		if (map->fields[i] == FIELD_SPRITE)
		{
			sprites_num++;
		}
		i++;
	}
	return (sprites_num);
}
