/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_scene.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:12 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/05 15:58:41 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_SCENE_H
# define RENDER_SCENE_H

# include "map.h"
# include "style.h"
# include "engine_state.h"
# include "intersection.h"

void		render_scene(t_map *map, t_style *style);
void	    init_engine_state(t_engine_state *engine_state, t_map *map);

#endif