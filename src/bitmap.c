/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 21:47:08 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/23 18:58:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"
#include "report_error.h"
#include "result.h"

#include <fcntl.h>
#include <unistd.h>

/*
** ypixelpermeter & xpixelpermeter- 72 dpi
*/

void	init_bmp(t_bmp *bmp, t_game_engine_state *state)
{
	int pixel_byte_size; // to a separate function?

	pixel_byte_size = state->style->resolution.x * state->style->resolution.y * (state->window->bits_per_pixel / 8);
	ft_memmove(bmp->bmpheader.signature_bytes, "BM", 2);
	bmp->bmpheader.filesize = pixel_byte_size + sizeof(bmp);
	bmp->bmpheader.reserved_bytes = 0;
	bmp->bmpheader.pixel_data_offset = sizeof(bmp);
	bmp->bmpinfoheader.size_of_this_header = sizeof(bmp->bmpinfoheader);
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
** Using 0644 in read system call will create a file that is Read/Write for owner,
** and Read Only for everyone else.
*/

int	create_bmp_file(t_game_engine_state	*state)
{
	t_bmp	bmp;
	int		fd;
	unsigned int	y;
	int		add;
	int		img_width;

	init_bmp(&bmp, state);
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		return (report_error("Unable to create a bmp file"));
	write(fd, (char *)&bmp.bmpheader, 14);
	write(fd, (char *)&bmp.bmpinfoheader, 40);
	// y = state->style->resolution.y - 1;
	y = 0;
	img_width = bmp.bmpinfoheader.width * (bmp.bmpinfoheader.bitsperpixel / 8);
	while (y < bmp.bmpinfoheader.height)
	{
		add = y * state->window->line_length;
		write(fd, ((char*)&state->window->addr[add]), img_width);
		y++;
	}
	return (SUCCESS);
}

