/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 16:13:25 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/05 15:45:05 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_RESOLUTION_H
# define PARSE_RESOLUTION_H

# include "resolution.h"

# define ERROR 0
# define SUCCESS 1
# define NOT_FOUND -1


int		parse_window_resolution(char *line, int line_num, t_resolution *resolution);
int		parse_resolution_components(char *str_start, int line_num, t_resolution *resolution);


#endif