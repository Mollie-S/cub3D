/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 13:43:26 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/05 13:48:00 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_MAP_H
# define VALIDATE_MAP_H

#include "map.h"

int		validate_map(t_map *map, t_style *style);
int		ft_floodfill(size_t x, size_t y, char *check_array, t_map *map);
int     is_closed_by_walls(t_map *map);
void	remove_outside_sprites(t_map *map, char *check_array);
int		count_sprites(t_map *map);

#endif
