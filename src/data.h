/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 18:58:39 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/12 19:17:22 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifdef DATA_H
# define DATA_H

typedef struct		s_data
{
	void    *img;
	char    *address;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               	t_data;

#endif