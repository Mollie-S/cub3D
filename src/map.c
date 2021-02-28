/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:06:50 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/27 22:58:22 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // remove the header!!!
#include <stdlib.h>

#include "libft.h"

#include "map.h"
#include "report_error.h"
#include "result.h"

void			init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->start_direction = -1;
	map->start_pos_x = -1;
	map->start_pos_y = -1;
	map->fields = NULL;
	map->sprites_num = 0;
}

void			free_map(t_map *map)
{
	free(map->fields);
	map->fields = NULL;
}

static int		ft_floodfill(size_t x, size_t y, char *check_array, t_map *map)
{
	size_t field_index;

	field_index = map->width * y + x;
	if (map->fields[field_index] == FIELD_BLACK_HOLE)
		return (report_error("There is a whitespace inside your map."));
	if (map->fields[field_index] != FIELD_WALL && check_array[field_index] == 0)
	{
		if (x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
			return (report_error("Your map is not surrounded by walls"));
		check_array[field_index] = 1;
		// debug_print_floodfill_map(map, check_array);
		if (!ft_floodfill(x + 1, y, check_array, map))
			return (ERROR);
		else if (!ft_floodfill(x - 1, y, check_array, map))
			return (ERROR);
		else if (!ft_floodfill(x, y + 1, check_array, map))
			return (ERROR);
		else if (!ft_floodfill(x, y - 1, check_array, map))
			return (ERROR);
	}
	return (SUCCESS);
}

void	remove_outside_sprites(t_map *map, char *check_array)
{
	int	map_size;
	int	i;

	map_size = map->height * map->width;
	i = 0;
	while (i < map_size)
	{
		if (check_array[i] == 0 && map->fields[i] != FIELD_WALL)
		{
			map->fields[i] = FIELD_BLACK_HOLE;
		}
		i++;
	}
}

int				validate_map(t_map *map, t_style *style)
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
	remove_outside_sprites(map, check_array);
	// debug_print_floodfill_map(map, check_array);
	free(check_array);
	check_array = NULL;
	map->sprites_num = count_sprites(map);
	if (map->sprites_num == 0 && style->textures[TEXTURE_SPRITE] != NULL)
		return(report_error("The texture for sprites is stated but the map contains no sprites "));
	return (SUCCESS);
}

int	count_sprites(t_map *map)
{
	int	map_size;
	int sprites_num;
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

// remove this function before submossion!
void			debug_print_floodfill_map(t_map *map, char *check_array)
{
	unsigned int y;
	unsigned int x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (check_array[y * map->width + x] == 0)
				printf("%c", map->fields[y * map->width + x]);
			else
				printf("x");
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void			debug_print_map(t_map *map)
{
	unsigned int y;
	unsigned int x;

	y = 0;
	printf("map->height:%lu\n", map->height);
	printf("map->width:%lu\n", map->width);
	printf("map->start_direction:%d\n", map->start_direction);
	printf("map->start_pos_x:%d\n", map->start_pos_x);
	printf("map->start_pos_y:%d\n", map->start_pos_y);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			printf("%c", map->fields[y * map->width + x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
