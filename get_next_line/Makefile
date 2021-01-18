# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: osamara <osamara@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/18 12:30:09 by osamara       #+#    #+#                  #
#    Updated: 2021/01/18 12:31:41 by osamara       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
INCL_DIR = include/

SRC = get_next_line.c \
	get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS)  -I $(INCL_DIR) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
