# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raho <raho@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:17:08 by raho              #+#    #+#              #
#    Updated: 2022/09/04 20:42:34 by raho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
LIBFTINCL = libft/
MLXLIB = /usr/local/lib
MLXINCL = /usr/local/include
FRACTOLINCL = ./
SRCS = main.c hooks.c draw_set.c fractals.c	initialize_struct.c	\
		mapping_functions.c
OBJS = $(SRCS:.c=.o)
MLXLINK = -lmlx -framework OpenGL -framework Appkit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -I $(LIBFTINCL) -I $(MLXINCL) \
	-I $(FRACTOLINCL) $(MLXLINK) -o $(NAME)

$(LIB):
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
