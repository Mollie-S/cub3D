/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_engine_state.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:16 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 21:45:54 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_STATE_H
# define GAME_ENGINE_STATE_H

# include "window.h"
# include "style.h"
# include "map.h"

typedef struct		s_game_engine_state
{
	double		dist_to_plane;
	double		pos_x;
	double		pos_y;
	t_window	*window;
	t_style		*style;
	t_map		*map;
}					t_game_engine_state;

#endif