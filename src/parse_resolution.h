/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_resolution.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 16:13:25 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/23 16:52:59 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_RESOLUTION_H
# define PARSE_RESOLUTION_H

# define ERROR 0
# define SUCCESS 1

int		parse_window_resolution(char *line, int line_num);
int		parse_resolution_components(char *str_start, int line_num);


#endif