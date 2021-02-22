/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 21:47:05 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/22 22:59:57 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

#include "window.h"

#include "libft.h"

#include <stdint.h>

typedef struct	s_bmp_header {
	uint8_t		signature_bytes[2];
	uint32_t	filesize;
	uint32_t	reserved_bytes;
	uint32_t	pixel_data_offset;
}				t_bmp_header;

typedef struct	s_bmp_infoheader {
	uint32_t	dibheadersize;
	uint32_t	width;
	uint32_t	height;
	uint16_t	planes;
	uint16_t	bitsperpixel;
	uint32_t	compression;
	uint32_t	imagesize;
	uint32_t	ypixelpermeter;
	uint32_t	xpixelpermeter;
	uint32_t	numcolorspallette;
	uint32_t	mostimpcolor;
}				t_bmp_infoheader;

typedef struct	s_bmp {
	t_bmp_header		bmpheader;
	t_bmp_infoheader	bmpinfoheader;
}				t_bmp;

#endif
