/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 21:47:05 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 19:41:30 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include "game_engine/game_engine_state.h"

# include "libft.h"

# include <stdint.h>

/*
** Structures needed for creating bmp
*/

typedef struct s_bmp_header {
	uint32_t	filesize;
	uint32_t	reserved_bytes;
	uint32_t	pixel_data_offset;
}				t_bmp_header;

typedef struct s_bmp_infoheader {
	uint32_t	size_of_this_header;
	uint32_t	width;
	uint32_t	height;
	uint16_t	number_of_color_planes;
	uint16_t	bitsperpixel;
	uint32_t	compression_method;
	uint32_t	raw_bmp_data_size;
	uint32_t	ypixelpermeter;
	uint32_t	xpixelpermeter;
	uint32_t	numcolorspallette;
	uint32_t	important_colors;
}				t_bmp_infoheader;

typedef struct s_bmp {
	t_bmp_header		bmpheader;
	t_bmp_infoheader	bmpinfoheader;
}				t_bmp;

int	create_bmp_file(t_game_engine_state	*state);
#endif
