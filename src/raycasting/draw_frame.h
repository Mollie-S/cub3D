/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:22:53 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 16:07:29 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_FRAME_H
# define DRAW_FRAME_H

# include "window.h"
# include "intersection.h"
# include "resolution.h"

void	draw_vertical_line(t_window *window, t_intersection_result *inters_res, t_resolution *resolution, int *num);
void	my_mlx_pixel_put(t_window *window, int x, int y, unsigned int color);
void	draw_image(t_window *window);

#endif
