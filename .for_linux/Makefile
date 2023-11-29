# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 01:29:49 by jinhyeok          #+#    #+#              #
#    Updated: 2023/11/29 03:04:15 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
#CFLAGS = -Wall -Wextra -Werror -Iinclude -I./minilibx-linux/
CFLAGS = -Iinclude -I./minilibx-linux/
LDFLAGS = -L./minilibx-linux  -lmlx -lXext -lX11 -lm

TARGET = miniRT

SRC = ./main.c \
	./vector.c \
	./vector2.c \
	./vector3.c \
	./vector4.c \
	./vector5.c \
	./color.c \
	./sphere.c \
	./trace.c \
	./camera.c
	

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re : clean
	make all


.PHONY: all clean