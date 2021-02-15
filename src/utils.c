/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 22:36:44 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/14 23:31:56 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double  wrap_angle(double angle)
{
    while (angle < 0.0)
        angle += 360.0;
    while (angle > 360.0)
        angle -= 360.0;
    return (angle);
}

void    swap(double *first, double *second)
{
    double temp;

    temp = *first;
    *first = *second;
    *second = temp;
}
