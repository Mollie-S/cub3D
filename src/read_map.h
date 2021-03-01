/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:31 by osamara       #+#    #+#                 */
/*   Updated: 2021/03/01 18:33:17 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include "libft.h"

# include "style.h"
# include "map.h"

int		parse_cub_map(char *file, t_style *style, t_map *map);
int		load_map_from_file(char *file, t_style *style, t_list **list_start);
int		read_from_file(int fd, char *line, t_style *style, t_list **list_start);
int		parse_map_line(char *line, int line_num, t_list **list_start);
int		push_line_to_llist(t_list **list_start, char *line, int line_num);

#endif
