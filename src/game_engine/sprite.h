/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 17:32:24 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/25 17:39:11 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "game_engine_state.h"

void    init_sprite(t_game_engine_state *state, t_sprite *sprite);
int     load_sprite_coordinates(t_game_engine_state *state);

#endif
