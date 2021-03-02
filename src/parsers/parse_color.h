/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_color.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:07:45 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 23:15:01 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_COLOR_H
# define PARSE_COLOR_H

# include "style.h"

# define ERROR 0
# define SUCCESS 1
# define NOT_FOUND -1

int		parse_colors(char *line, int line_num, t_style *style);
int		get_color_value(unsigned int *rgb, char *line, int line_num,
			    int identifier_len);
int		validate_color(char *line, unsigned int *color);
int		is_valid_color_component(char **array, int *red, int *green, int *blue);

#endif
