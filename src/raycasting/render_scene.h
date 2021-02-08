/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:12 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 23:31:28 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_SCENE_H
# define RENDER_SCENE_H

# include "game_engine/game_engine_state.h"
# include "intersection.h"

/*
**	adding (double)(0.0001) to radian to avoid division by 0 in case with tan(radian) or cos(radian)
*/

# define FOV 60
# define DEG2RAD(angle) ((angle) * M_PI / 180.0 + (double)(0.0001))
# define RAD2DEG(angle) ((angle) * 180.0 / M_PI


void		render_scene(t_game_engine_state *state);
void		define_current_wall(t_game_engine_state *state, t_tracer *tracer, t_intersection_result *inters_result);


#endif