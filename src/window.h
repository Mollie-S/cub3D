/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 17:33:01 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/07 20:45:06 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct		s_window
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*address;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}					t_window;

#endif