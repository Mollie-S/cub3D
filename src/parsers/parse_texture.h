/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:04:08 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/10 15:07:40 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TEXTURE_H
# define PARSE_TEXTURE_H

# include "style.h"

# define ERROR 0
# define SUCCESS 1
# define NOT_FOUND -1

int		parse_walls_textures(char *line, int line_num, t_style *style);
int		validate_texture(char *path_name, int line_num);

#endif