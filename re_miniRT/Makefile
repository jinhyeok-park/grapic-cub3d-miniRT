# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 17:24:31 by jinhyeok          #+#    #+#              #
#    Updated: 2024/01/06 15:09:12 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ./src/main.c\
			./src/color3.c\
			./src/pixel.c\
			./src/vector1.c\
			./src/vector2.c\
			./src/vector3.c\
			./src/vector4.c\
			./src/camera.c\
			./src/sphere.c\
			./src/trace.c\
			./src/trace2.c\
			./src/trace3.c\
			./src/object.c\
			./src/scene.c\
			./src/record.c\
			./src/light.c\
			./src/plane.c\
			./src/cylinder.c\
			./src/parsing.c\
			./src/parsing_utils.c\
			./src/parsing_get.c\
			./src/parsing_initial.c\
			./src/parsing_object.c\
			./src/scene_init.c\
			./src/exit.c\
			./src/cylinder_utils.c\
			./src/cylinder_hits.c\

INCLUDES = ./include

M_OBJ = $(SOURCES:./src/.c=.o)
B_OBJ = $(SOURCES_BONUS:./src_bonus/.c=.o)

ifdef BONUS
	OBJECTS = $(B_OBJ)
	NAME = miniRT_bonus
else
	OBJECTS = $(M_OBJ)
	NAME = miniRT
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	make -C mlx
	cp ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $^ -I./libft -Llibft -lft -I./mlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ -I $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	make -C mlx clean

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf ./mlx/libmlx.dylib
	rm -rf libmlx.dylib

re: fclean all

.PHONY: all clean fclean re