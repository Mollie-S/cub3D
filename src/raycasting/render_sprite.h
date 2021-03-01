/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_sprite.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 14:26:25 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 17:56:26 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_SPRITE_H
# define RENDER_SPRITE_H

# include "game_engine/game_engine_state.h"

void	handle_sprites(t_game_engine_state *state);
void	sort_sprites(t_game_engine_state *state);
void	calc_dist_to_sprites(t_game_engine_state *state);
void	calc_sprite_pos_on_screen(t_game_engine_state *state, t_sprite *sprite);
void	calc_sprite_draw_range(t_game_engine_state *state,
			    t_sprite *sprite, double sprite_screen_x);

#endif
