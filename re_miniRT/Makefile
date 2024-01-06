# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 17:24:31 by jinhyeok          #+#    #+#              #
#    Updated: 2024/01/06 19:07:31 by minjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

NAME = miniRT
BONUS_NAME = miniRT_bonus

SRC_DIR = src
OBJ_DIR = obj
BONUS_SRC_DIR = src_bonus
BONUS_OBJ_DIR = obj_bonus
INC_DIR = includes

SRCS_NAMES = main.c color3.c pixel.c vector1.c vector2.c vector3.c vector4.c camera.c \
             sphere.c trace.c trace2.c trace3.c object.c scene.c record.c light.c \
             plane.c cylinder.c parsing.c parsing_utils.c parsing_get.c parsing_initial.c \
             parsing_object.c scene_init.c exit.c cylinder_utils.c cylinder_hits.c
SRCS_BONUS_NAMES = main_bonus.c color3_bonus.c pixel_bonus.c vector1_bonus.c vector2_bonus.c \
                   vector3_bonus.c vector4_bonus.c camera_bonus.c sphere_bonus.c trace_bonus.c \
                   trace2_bonus.c trace3_bonus.c object_bonus.c scene_bonus.c record_bonus.c \
                   light_bonus.c plane_bonus.c cylinder_bonus.c parsing_bonus.c \
                   parsing_utils_bonus.c parsing_get_bonus.c parsing_initial_bonus.c \
                   parsing_object_bonus.c scene_init_bonus.c exit_bonus.c cylinder_utils_bonus.c \
                   cylinder_hits_bonus.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_NAMES))
OBJS = $(SRCS_NAMES:%.c=$(OBJ_DIR)/%.o)
SRCS_BONUS = $(addprefix $(BONUS_SRC_DIR)/, $(SRCS_BONUS_NAMES))
OBJS_BONUS = $(SRCS_BONUS_NAMES:%.c=$(BONUS_OBJ_DIR)/%.o)

ifdef BONUS
    OBJECTS = $(OBJS_BONUS)
    NAME = $(BONUS_NAME)
else
    OBJECTS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft
	make -C mlx
	cp ./mlx/libmlx.dylib ./libmlx.dylib
	$(CC) $(OBJECTS) -I./libft -Llibft -lft -I./mlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ -I $(INC_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BONUS_OBJ_DIR):
	@mkdir -p $@

bonus:
	make BONUS=1 all

clean:
	make -C libft clean
	make -C mlx clean
	rm -f $(OBJS) $(OBJS_BONUS)
	rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f ./mlx/libmlx.dylib
	rm -f libmlx.dylib

re: fclean all

.PHONY: all clean fclean re bonus
