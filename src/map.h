/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 12:53:44 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/20 21:32:37 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct		s_scene_descript
{
	char		*identifier;

	int			resolution_x;
	int			resolution_y;
	char		*texture;
	char		*no_texture;
	char		*so_texture;
	char		*ea_texture;
	char		*we_texture;
	char		*sprite_texture;
}					t_scene_descript;

typedef struct		s_color
{
	char	identifier;
	int		*floor_rgb;
	int		*ceiling_rgb;
}					t_color;

typedef struct		s_map
{
	int			height;
	int			width;
	int			start_direction;
	double		start_pos_x;
	double		start_pos_y;
	char		*fields;
}					t_map;


#endif