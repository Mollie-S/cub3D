/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 20:04:19 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/08 18:49:26 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <stddef.h>

typedef struct      s_intersection
{
	double	x;
	double	y;
	double	step_x;
	double	step_y;
	char	type;
}                   t_intersection;

typedef struct      s_intersection_result
{
	double	dist_to_wall;
	double	wall_height; // will it be here?
	int		is_side_wall;
	char	*current_texture;
	unsigned int current_color;
	size_t	texture_x;
	size_t	texture_y;
}					t_intersection_result;


#endif