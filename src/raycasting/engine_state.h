/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   engine_state.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/31 22:26:16 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/31 22:28:45 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_STATE_H
# define ENGINE_STATE_H

typedef struct s_engine_state
{
    double      start_pos_x;
    double      start_pos_y;
    int         fov;
}               t_engine_state;


#endif