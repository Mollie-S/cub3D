/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 17:04:08 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/23 17:05:03 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TEXTURE_H
# define PARSE_TEXTURE_H

# define ERROR 0
# define SUCCESS 1

int		parse_walls_textures(char *line, int line_num);
char	*parse_texture_path(char *line);


#endif