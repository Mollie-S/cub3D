/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:56:31 by osamara       #+#    #+#                 */
/*   Updated: 2021/01/21 22:19:02 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include "../libft/include/libft.h"


# define ERROR 0
# define SUCCESS 1
# define END_OF_FILE 0

int		open_file(char *file);
int		read_from_file(int fd);
int		push_line_to_llist(t_list **list_start, char *line);
int		handle_lines_read(char *line, int line_num);

int		report_error(int line_num, char *message);



#endif