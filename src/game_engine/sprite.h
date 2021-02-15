/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 17:32:24 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/14 23:26:45 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "game_engine_state.h"

void	init_sprite(t_sprite *sprite);
void	load_sprites(t_game_engine_state *state);
int		count_sprites(t_map *map);
void	load_sprite_coordinates(t_game_engine_state *state, int	sprites_num);
void	sort_sprites(t_game_engine_state *state, int sprites_num);


#endif
