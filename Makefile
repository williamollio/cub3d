# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiliamollio <wiliamollio@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 19:15:15 by wollio            #+#    #+#              #
#    Updated: 2022/04/19 11:43:30 by wiliamollio      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
PATH_LIBFT = ./libft/libft.a
PATH_MLX = ./mlx/libmlx.a
NAME = cub3D
SOURCES =	./src/main.c \
			./src/parsing/read_files.c ./src/parsing/extract_content.c ./src/parsing/extract_content_utils.c\
			./src/parsing/extract_content_utils2.c ./src/parsing/map_valid.c ./src/parsing/map_valid_utils.c \
			./src/parsing/utils.c ./src/parsing/utils_list.c ./src/parsing/map_valid_utils2.c \
			./src/init/calc.c ./src/render/minimap.c \
			./src/movement/movement.c ./src/init/init.c ./src/logic/hooks.c ./src/logic/math.c \
			./src/render/texture.c ./src/render/floor_ceilling.c ./src/finish/error.c ./src/movement/walk.c \
			./src/render/draw.c ./src/movement/walk2.c \
			./src/logic/mlx.c ./src/finish/free.c \
			./src/gnl/get_next_line.c ./src/gnl/get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(PATH_LIBFT):
	make -C ./libft
	make -C ./mlx

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

$(NAME): $(PATH_LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(PATH_LIBFT) $(PATH_MLX) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJECTS)
	make clean -C ./libft
	make clean -C ./mlx

fclean: clean
	$(RM) $(NAME)
	$(RM) ./libft/libft.a
	$(RM) ./mlx/libmlx.a
	$(RM) cub3D

re: fclean all
