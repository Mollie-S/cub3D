/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 19:07:21 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/20 19:11:31 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "map.h"
#include "../libft/include/libft.h"

# define ERROR 0
# define SUCCESS 1

int		parse_map(t_list *list_start);
int		calculate_map_size(t_list *list_start, t_map *map);


#endif