/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   style.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 21:51:42 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 21:07:45 by osamara       ########   odam.nl         */
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

typedef struct		s_texture_identifier
{
	char			*identifier;
	t_texture_index	index;
}					t_texture_identifier;

typedef struct		s_style
{
	char			*textures[TEXTURE_COUNT];
	unsigned int	floor_rgb;
	unsigned int	ceiling_rgb;
	t_resolution    resolution;
}					t_style;

void	init_map_style(t_style *style);
int     validate_style(t_style *style);
void	free_map_style(t_style *style);
void	debug_print_style(t_style *style); //remove!


#endif
