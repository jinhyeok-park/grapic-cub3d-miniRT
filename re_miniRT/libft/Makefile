# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjcho <minjcho@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 17:14:25 by minjcho           #+#    #+#              #
#    Updated: 2024/01/03 11:47:58 by minjcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc

NAME = libft.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRCS_NAMES =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c \
				ft_putstr.c \
				ft_printf.c ft_printf_utils.c \
				get_next_line.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_NAMES))
OBJS = $(SRCS_NAMES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) created successfully."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) cleaned successfully."

re: fclean all

.PHONY: all clean fclean re
