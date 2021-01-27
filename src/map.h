/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 12:53:44 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/27 13:52:32 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

/*
** it could have been better not to initialize enum to let them be 0,1 etc
** but this way it's more visual for testing the map I'm parsing
*/

typedef enum		e_field {
	FIELD_BLACK_HOLE = ' ',
	FIELD_EMPTY = '0',
	FIELD_WALL = '1',
	FIELD_SPRITE = '2'
}					t_field;

typedef struct		s_map
{
	size_t			height;
	size_t			width;
	int				start_direction;
	int				start_pos_x;
	int				start_pos_y;
	char			*fields;
}					t_map;

void				init_maze_map(t_map *map);
//void    free_maze_map(t_map *map);

#endif
