/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:12 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/04 10:06:59 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_SCENE_H
# define RENDER_SCENE_H

#include "engine_state.h"
#include "map.h"
#include "result.h"

typedef struct      s_intersection
{
    double x;
    double y;
    double step_x;
    double step_y;
}                   t_intersection;

void		render_scene(t_map *map);
void	init_engine_state(t_engine_state *engine_state, t_map *map);


#endif