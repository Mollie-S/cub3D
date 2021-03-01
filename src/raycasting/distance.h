/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distance.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:43:30 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/28 23:41:27 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_H
# define DISTANCE_H

# include "game_engine/game_engine_state.h"
# include "intersection.h"

double	dist_to_hor_inters(t_game_engine_state *state, t_tracer *hor_inters);
double	dist_to_ver_inters(t_game_engine_state *state, t_tracer *vert_inters);
double	distance_to_wall(t_game_engine_state *state, t_tracer *tracer);

#endif
