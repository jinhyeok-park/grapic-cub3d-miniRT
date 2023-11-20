# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:09:00 by jinhyeok          #+#    #+#              #
#    Updated: 2023/04/06 15:41:41 by jinhyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES = ft_printf1.c ft_printf2.c ft_printf3.c

M_OBJ = $(SOURCES:.c=.o)

all	: $(NAME)

$(NAME) : $(M_OBJ)
	make -C libft all
	cp ./libft/libft.a ./$(NAME)
	ar -rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean :
	rm -rf $(M_OBJ)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	rm -rf ./libft/libft.a 

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus