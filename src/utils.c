/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:36:44 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 22:39:16 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double		wrap_angle(double angle)
{
    while (angle < 0.0)
        angle += 360.0;
    while (angle > 360.0)
        angle -= 360.0;
    return (angle);
}