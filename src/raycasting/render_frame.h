/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_frame.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:12 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/09 16:03:25 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_FRAME_H
# define RENDER_FRAME_H

# include "game_engine/game_engine_state.h"
# include "intersection.h"

/*
**	adding (double)(0.0001) to radian to avoid division by 0 in case with tan(radian) or cos(radian)
*/


int		render_frame(t_game_engine_state *state);
void		define_current_wall(t_game_engine_state *state, t_tracer *tracer, t_intersection_result *inters_result);


#endif