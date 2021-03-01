/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 21:47:08 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 19:03:38 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"
#include "report_error.h"
#include "result.h"

#include <fcntl.h>
#include <unistd.h>

/*
** ypixelpermeter & xpixelpermeter- 72 dpi
**
** 2 bytes are added to filesize and pixel data offset
** because BM is removed from s_bmp_header struct
** as it was creating a padding.
** One way to avoid padding is to use #pragma(push and pop)
** but Norminette call this define as unrecognizable.
** Therefore BM is written separately.
*/

void	init_bmp(t_bmp *bmp, t_game_engine_state *state)
{
	int	pixel_byte_size;

	pixel_byte_size = state->style->resolution.x * state->style->resolution.y
		* (state->window->bits_per_pixel / 8);
	bmp->bmpheader.filesize = 2 + pixel_byte_size + sizeof(t_bmp);
	bmp->bmpheader.reserved_bytes = 0;
	bmp->bmpheader.pixel_data_offset = 2 + sizeof(t_bmp);
	bmp->bmpinfoheader.size_of_this_header = sizeof(t_bmp_infoheader);
	bmp->bmpinfoheader.width = state->style->resolution.x;
	bmp->bmpinfoheader.height = state->style->resolution.y;
	bmp->bmpinfoheader.number_of_color_planes = 1;
	bmp->bmpinfoheader.bitsperpixel = state->window->bits_per_pixel;
	bmp->bmpinfoheader.compression_method = 0;
	bmp->bmpinfoheader.raw_bmp_data_size = 0;
	bmp->bmpinfoheader.ypixelpermeter = 2835;
	bmp->bmpinfoheader.xpixelpermeter = 2835;
	bmp->bmpinfoheader.numcolorspallette = 0;
	bmp->bmpinfoheader.important_colors = 0;
}

/*
** Using 0644 in read system call will create a file
** that is Read/Write for owner,
** and Read Only for everyone else.
*/

int	create_bmp_file(t_game_engine_state	*state)
{
	t_bmp			bmp;
	int				fd;
	unsigned int	y;
	int				img_width;

	init_bmp(&bmp, state);
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		return (report_error("Unable to create a bmp file"));
	write(fd, "BM", 2);
	write(fd, (char *)&bmp, sizeof(bmp));
	y = bmp.bmpinfoheader.height;
	img_width = bmp.bmpinfoheader.width * (bmp.bmpinfoheader.bitsperpixel / 8);
	while (y > 0)
	{
		write(fd, ((char *)state->window->addr + (y - 1)
			* state->window->line_length), img_width);
		y--;
	}
	return (SUCCESS);
}
