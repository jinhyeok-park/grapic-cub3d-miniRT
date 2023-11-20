# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 21:30:27 by jinhyeok          #+#    #+#              #
#    Updated: 2023/11/17 22:51:49 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
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

SOURCES_BONUS =

INCLUDES = includes

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
	make -C ft_printf
	make -C mlx
	cp ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $^ -Lft_printf -lftprintf -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ -I $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
bonus :
	make BONUS=1 all

clean:
	make -C ft_printf clean
	make -C mlx clean

fclean: clean
	rm -rf $(NAME)
	rm -rf ./so_long_bonus
	rm -rf ./libftprintf.a
	rm -rf ./mlx/libmlx.dylib
	rm -rf libmlx.dylib

re: fclean all

.PHONY: all clean fclean re