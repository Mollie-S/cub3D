/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_header.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 11:59:47 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/28 14:45:11 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_HEADER_H
# define PARSE_MAP_HEADER_H

# include "style.h"

int		parse_map_header(char *line, int line_num, t_style *style);

#endif