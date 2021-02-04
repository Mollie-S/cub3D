/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osamara <osamara@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/23 16:52:24 by osamara       #+#    #+#                 */
/*   Updated: 2021/02/03 19:49:46 by osamara       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_UTILS_H
# define PARSING_UTILS_H

int		        are_valid_characters(char *line, int line_num);
int		        is_empty_line(char *line);
int		        has_identifier(char *line, char *identifier, int *identifier_len);
int		        is_valid_component(const char *string, int *component);
char			**split_into_components(char *line, char separator, int num_components);
void		    free_array_memory(char **array);

#endif
