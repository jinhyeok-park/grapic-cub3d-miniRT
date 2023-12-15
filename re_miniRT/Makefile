# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 16:16:36 by jinhyeok          #+#    #+#              #
#    Updated: 2023/12/04 16:46:44 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_FILES = main.c 

SOURCES = $(addprefix src/, $(SRC_FILES))
INCLUDES = include

M_OBJ = $(SOURCES:./src/.c=.o)

OBJECTS = $(M_OBJ)
NAME = miniRT

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C mlx
	cp ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $^ -I./mlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ -I $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C mlx clean

fclean: clean
	rm -rf $(NAME)
	rm -rf ./mlx/libmlx.dylib
	rm -rf libmlx.dylib

re: fclean all

.PHONY: all clean fclean re