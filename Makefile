# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: osamara <osamara@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/11 22:14:55 by osamara       #+#    #+#                  #
#    Updated: 2021/03/02 00:26:16 by osamara       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME =		cub3D

SRC = \
	src/main.c \
	src/check_arguments.c \
	src/style.c \
	src/map.c \
	src/read_map.c \
	src/report_error.c \
	src/window.c \
	src/utils.c \
	src/bitmap.c \
	src/parsers/parse_map_header.c \
	src/parsers/parse_resolution.c \
	src/parsers/parse_color.c \
	src/parsers/parse_texture.c \
	src/parsers/parsing_utils.c \
	src/parsers/parse_map.c \
	src/raycasting/distance.c \
	src/raycasting/render_frame.c \
	src/raycasting/init_intersection.c \
	src/raycasting/draw_frame.c \
	src/raycasting/render_sprite.c \
	src/game_engine/game_loop.c \
	src/game_engine/key_handling.c \
	src/game_engine/sprite.c \
	src/game_engine/movement.c

SRC_B = src/raycasting/sample_skybox_bonus.c
SRC_STUB = src/raycasting/sample_skybox_default.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
OBJ_STUB = $(SRC_STUB:.c=.o)
CFLAGS = -Wall -Werror -Wextra -O0 -g

INCLUDES =	./get_next_line \
			./libft \
			./mlx

ifdef BONUS
OBJS = $(OBJ) $(OBJ_B)
else
BONUS = 0
OBJS = $(OBJ) $(OBJ_STUB)
endif

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
			make -C libft/
			cp libft/libft.a .
			make -C mlx/
			cp mlx/libmlx.a .
			make -C get_next_line/
			cp get_next_line/libgnl.a .
			$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit \
			-Llibft -lft -Lget_next_line -lgnl \
			-o $(NAME) $(OBJS) $(CFLAGS)

%.o:		%.c
			$(CC) $(CFLAGS) -DBONUS=$(BONUS) -Ilibft/include \
			-Iget_next_line -Isrc -Imlx -c $< -o $@

bonus:
			$(MAKE) BONUS=1 all

clean:
			/bin/rm -f $(OBJS)
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
