/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 19:07:21 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/06 20:01:47 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "map/map.h"
# include "libft.h"

int		parse_map(t_list *list_start, t_map *map);
int		calculate_map_size(t_list *list_start, t_map *map);
int		fill_map_fields(t_list *list_start, t_map *map);
int		define_start_position(t_list *current, t_map *map, int y);
int		define_start_direction(char c, int *start_direction);

#endif
