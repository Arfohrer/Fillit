# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arfohrer <arfohrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 16:10:04 by arfohrer          #+#    #+#              #
#    Updated: 2018/05/16 16:51:13 by arfohrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_check_error.c \
			ft_error.c \
			create_grid.c \
			fill_grid.c \
			get_information.c \
			piece_top_left.c \

OBJ = $(SRC_NAME:.c=.o)

INC = -I .

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC) 

LIBFT_PATH = libft
NAME = fillit

.PHONY: all, clean, fclean, re

all: libftcomp $(NAME)

$(NAME): $(OBJ) fillit.h
	$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT_PATH) -lft -o $(NAME)

libftcomp:
		make -C $(LIBFT_PATH)
clean:
	rm -fv $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean:
	rm -fv $(OBJ)
	rm	-fv	$(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all
