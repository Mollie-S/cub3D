/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:22:53 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 08:50:17 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_FRAME_H
# define DRAW_FRAME_H

# include "intersection.h"
# include "game_engine/game_engine_state.h"

void	        draw_vertical_line(t_game_engine_state *state, t_intersection_result *result, int x, double ray_angle);
void			draw_sprites_vertical_pixels(t_game_engine_state *state, int x, double dist_to_wall);
unsigned int	sample_texture(t_texture_info *texture, double tex_x, double tex_y);

#endif
