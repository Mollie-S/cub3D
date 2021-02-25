/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_engine_state.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:16 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 21:45:54 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_STATE_H
# define GAME_ENGINE_STATE_H

# include "window.h"
# include "style.h"
# include "map.h"


typedef struct		s_movement
{
	int		rotation_dir;
	int		move_ver_dir;
	int		move_hor_dir;
	double	next_pos_x;
	double	next_pos_y;
}					t_movement;

typedef struct		s_texture_info
{
	void		*img;
	int			img_width;
	int			img_height;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}					t_texture_info;

typedef struct s_sprite
{
	double			x;
	double			y;
	double			dist_to_sprite;
	t_texture_info	*sprite_tex_info;
	double			draw_min_x;
	double			draw_max_x;
	double			draw_min_y;
	double			draw_max_y;
}               t_sprite;

typedef struct		s_game_engine_state
{
	double			dist_to_plane;
	double			pos_x;
	double			pos_y;
	double			direction;
	t_texture_info	tex_info[TEXTURE_COUNT];
	t_window		*window;
	t_style			*style;
	t_map			*map;
	t_movement		move;
	t_sprite		*sprites;
}					t_game_engine_state;

#endif