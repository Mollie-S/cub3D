/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitmap.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 21:47:08 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/22 23:07:14 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bitmap.h"

void	init_bmp(t_bmp *bmp)
{
	ft_memmove(bmp->bmpheader.signature_bytes, "BM", 2);
}

void	create_bmp_file(t_window *window)
{
	t_bmp	bmp;
	init_bmp(&bmp);
}

