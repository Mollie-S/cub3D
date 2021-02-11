/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 23:22:53 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/11 12:18:38 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_FRAME_H
# define DRAW_FRAME_H

# include "intersection.h"
# include "game_engine/game_engine_state.h"

void	draw_vertical_line(t_game_engine_state *state, t_intersection_result *inters_res, int x);
void	draw_image(t_window *window);
unsigned int	sample_texture(t_intersection_result *result);


#endif
