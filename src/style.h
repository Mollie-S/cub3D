/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   style.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 21:51:42 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/28 18:08:44 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H

# include "resolution.h"

# define INVALID_COLOR 0xFFFFFFFF

typedef struct		s_style
{
	char			*no_texture;
	char			*so_texture;
	char			*ea_texture;
	char			*we_texture;
	char			*sprite_texture;
	unsigned int	floor_rgb;
	unsigned int	ceiling_rgb;
	t_resolution    start_resolution;
}					t_style;

void	init_map_style(t_style *style);
int     validate_style(t_style *style);
void	free_map_style(t_style *style);

#endif
