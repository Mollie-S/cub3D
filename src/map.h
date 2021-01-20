/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 12:53:44 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/19 17:51:25 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct		s_map
{
	int				height;
	int				width;
	int				start_direction;
	double			start_pos_x;
	double			start_pos_y;
}					t_map;


#endif