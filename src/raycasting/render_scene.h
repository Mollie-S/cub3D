/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:12 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/06 22:07:53 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_SCENE_H
# define RENDER_SCENE_H

# include "map.h"
# include "style.h"
# include "engine_state.h"
# include "intersection.h"

/*
**	adding (double)(0.0001) to radian to avoid division by 0 in case with tan(radian) or cos(radian)
*/
# define DEG2RAD(angle) ((angle) * M_PI / 180.0 + (double)(0.0001))
# define RAD2DEG(angle) ((angle) * 180.0 / M_PI
# define FOV 60

void		render_scene(t_map *map, t_style *style);
void		init_engine_state(t_engine_state *engine_state, t_map *map, t_resolution *resolution);


#endif