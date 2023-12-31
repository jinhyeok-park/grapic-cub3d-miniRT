# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 21:30:27 by jinhyeok          #+#    #+#              #
#    Updated: 2023/12/18 17:15:43 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = #-Wall -Wextra -Werror
SOURCES = ./src/main.c\
			./src/vector.c\
			./src/vector2.c\
			./src/vector3.c\
			./src/vector4.c\
			./src/vector5.c\
			./src/camera.c\
			./src/trace.c\
			./src/color.c\
			./src/sphere.c\
			./src/object.c\
			./src/scene.c\
			./src/light.c\
			./src/parsing.c\
			./src/get_next_line_utils.c\
			./src/get_next_line.c\

SOURCES_BONUS =

INCLUDES = ./includes

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