/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_sprite.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 14:26:29 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/24 14:29:31 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "render_sprite.h"

void    render_sprites(t_game_engine_state *state)
{
    sort_sprites(state);
}

void	calc_dist_to_sprites(t_game_engine_state *state, double *sprite_dist)
{
    int	i;

    i = 0;
    while (i < state->map->sprites_num)
    {
        sprite_dist[i] = pow(fabs(state->pos_x - state->sprites[i].x), 2.0)
            + pow(fabs(state->pos_y - state->sprites[i].y), 2.0);
        i++;
    }
}

void	sort_sprites(t_game_engine_state *state)
{
    double		sprite_dist[state->map->sprites_num];
    int 		i;
    int 		j;
    t_sprite	temp;

    i = 0;
    calc_dist_to_sprites(state, sprite_dist);
    while (i < state->map->sprites_num)
    {
        j = i + 1;
        while (j < state->map->sprites_num)
        {
            if (sprite_dist[j] > sprite_dist[i])
            {
                swap(&sprite_dist[i], &sprite_dist[j]);
                // swap_sprites(&state->sprites, i, j);  how to make a separate function for struct swaps?
                temp = state->sprites[i];
                state->sprites[i] = state->sprites[j];
                state->sprites[j] = temp;
            }
            j++;
        }
        i++;
    }
}