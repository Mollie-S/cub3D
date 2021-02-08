/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:12 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 09:08:47 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_SCENE_H
# define RENDER_SCENE_H

# include "map.h"
# include "style.h"
# include "engine_state.h"
# include "intersection.h"
# include "window.h"

/*
**	adding (double)(0.0001) to radian to avoid division by 0 in case with tan(radian) or cos(radian)
*/
# define TILE_SIZE 1.0
# define FOV 60
# define DEG2RAD(angle) ((angle) * M_PI / 180.0 + (double)(0.0001))
# define RAD2DEG(angle) ((angle) * 180.0 / M_PI

void		render_scene(t_map *map, t_style *style);
void		init_engine_state(t_engine_state *engine_state, t_map *map, t_resolution *resolution);


#endif