/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 19:07:21 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/27 17:20:04 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "map.h"
#include "../libft/include/libft.h"

# define ERROR 0
# define SUCCESS 1
# define NOT_FOUND -1

int		parse_maze_map(t_list *list_start, t_map *map);
int		calculate_map_size(t_list *list_start, t_map *map);
int		fill_map_fields(t_list *list_start, t_map *map);
int		check_start_position(t_list *current, t_map *map, int y);
int     set_start_direction(char c, int *start_direction);



#endif