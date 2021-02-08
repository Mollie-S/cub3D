# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: osamara <osamara@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/11 22:14:55 by osamara       #+#    #+#                  #
#    Updated: 2021/02/08 23:46:30 by osamara       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME =		cub3D

SRC = \
	src/cub3d.c \
	src/style.c \
	src/map.c \
	src/read_map.c \
	src/report_error.c \
	src/start_window.c \
	src/utils.c \
	src/parsers/parse_map_header.c \
	src/parsers/parse_resolution.c \
	src/parsers/parse_color.c \
	src/parsers/parse_texture.c \
	src/parsers/parsing_utils.c \
	src/parsers/parse_map.c \
	src/raycasting/distance.c \
	src/raycasting/draw_scene.c \
	src/raycasting/render_scene.c \
	src/game_engine/game_loop.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -O0 -g

INCLUDES =	./get_next_line \
			./libft \
			./mlx

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDES)
			make -C libft/
			cp libft/libft.a .
			make -C mlx/
			cp mlx/libmlx.a .
			make -C get_next_line/
			cp get_next_line/libgnl.a .
			$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft -Lget_next_line -lgnl \
			-o $(NAME) $(OBJ) $(CFLAGS)

%.o:		%.c
			$(CC) $(CFLAGS)  -Ilibft/include -Iget_next_line -Isrc -Imlx -c $< -o $@

clean:
			/bin/rm -f $(OBJ)
			make clean -C libft/
			make clean -C mlx/
			make clean -C get_next_line

fclean:		clean
			/bin/rm -f mlx/libmlx.a 
			/bin/rm -f libmlx.a 
			/bin/rm -f libft/libft.a
			/bin/rm -f libft.a
			/bin/rm -f get_next_line/libgnl.a
			/bin/rm -f libgnl.a
			/bin/rm -f screenshot.bmp
			/bin/rm -f $(NAME)

re:			fclean all
