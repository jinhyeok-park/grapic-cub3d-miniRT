# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 17:24:31 by jinhyeok          #+#    #+#              #
#    Updated: 2024/01/06 17:27:01 by minjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES =	./src/main.c\
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

SOURCES_BONUS =	./src_bonus/main_bonus.c\
				./src_bonus/color3_bonus.c\
				./src_bonus/pixel_bonus.c\
				./src_bonus/vector1_bonus.c\
				./src_bonus/vector2_bonus.c\
				./src_bonus/vector3_bonus.c\
				./src_bonus/vector4_bonus.c\
				./src_bonus/camera_bonus.c\
				./src_bonus/sphere_bonus.c\
				./src_bonus/trace_bonus.c\
				./src_bonus/trace2_bonus.c\
				./src_bonus/trace3_bonus.c\
				./src_bonus/object_bonus.c\
				./src_bonus/scene_bonus.c\
				./src_bonus/record_bonus.c\
				./src_bonus/light_bonus.c\
				./src_bonus/plane_bonus.c\
				./src_bonus/cylinder_bonus.c\
				./src_bonus/parsing_bonus.c\
				./src_bonus/parsing_utils_bonus.c\
				./src_bonus/parsing_get_bonus.c\
				./src_bonus/parsing_initial_bonus.c\
				./src_bonus/parsing_object_bonus.c\
				./src_bonus/scene_init_bonus.c\
				./src_bonus/exit_bonus.c\
				./src_bonus/cylinder_utils_bonus.c\
				./src_bonus/cylinder_hits_bonus.c\

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

bonus:
	make BONUS=1 all

clean:
	make -C libft clean
	make -C mlx clean

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf ./miniRT_bonus
	rm -rf ./mlx/libmlx.dylib
	rm -rf libmlx.dylib

re: fclean all

.PHONY: all clean fclean re