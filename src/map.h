/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 12:53:44 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/26 12:36:31 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct		s_map
{
	size_t			height;
	size_t			width;
	int				start_direction;
	double			start_pos_x;
	double			start_pos_y;
	char			**fields;
}					t_map;

void	init_maze_map(t_map *map);
void	free_maze_map(t_map *map);

#endif
