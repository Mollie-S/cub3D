/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   style.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 21:51:42 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/07 09:00:58 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H

# include "resolution.h"

# define INVALID_COLOR 0xFFFFFFFF

typedef enum		e_texture_index {
	TEXTURE_NO,
	TEXTURE_SO,
	TEXTURE_EA,
	TEXTURE_WE,
	TEXTURE_SPRITE,
	TEXTURE_COUNT
}					t_texture_index;

typedef enum		e_color_index {
	COLOR_NO = 0x00FFFFFF,
	COLOR_SO = 0x0000FF00,
	COLOR_EA = 0x00FF0000,
	COLOR_WE = 0x000000FF,
	// TEXTURE_SPRITE,
	COLOR_COUNT
}					t_color_index;

typedef struct		s_texture_identifier
{
	char			*identifier;
	t_texture_index	index;
}					t_texture_identifier;

typedef struct		s_style
{
	char			*textures[TEXTURE_COUNT];
	char			*colors[COLOR_COUNT]; //remove, it's for testing purposes!
	unsigned int	floor_rgb;
	unsigned int	ceiling_rgb;
	t_resolution    resolution;
}					t_style;

void	init_map_style(t_style *style);
int     validate_style(t_style *style);
void	free_map_style(t_style *style);
void	debug_print_style(t_style *style); //remove!


#endif
