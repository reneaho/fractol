# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raho <raho@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:17:08 by raho              #+#    #+#              #
#    Updated: 2023/02/21 15:17:18 by raho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
LIB = libft/libft.a
MLXLIB = /usr/local/lib
MLXINCL = /usr/local/include
SOURCE = main.c hooks.c draw_set.c fractals.c	initialize_struct.c	\
		mapping_functions.c
SRC = $(addprefix source/,$(SOURCE))
OBJ = $(SRC:.c=.o)
INCLUDE = -Iinclude -I $(MLXINCL) -Ilibft
MLXLINK = -lmlx -framework OpenGL -framework Appkit
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) $(LIB) $(INCLUDE) $(MLXLINK) -o $(NAME)

$(LIB):
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
