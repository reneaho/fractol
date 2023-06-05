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
LIBFT = libft/libft.a
SOURCE = main.c hooks.c draw_set.c fractals.c	initialize_struct.c	\
		mapping_functions.c
SRC = $(addprefix source/,$(SOURCE))
OBJ = $(SRC:.c=.o)
INCLUDE = -Iinclude -Ilibft
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

UNAME= $(shell uname)
ifeq ($(UNAME), Darwin)
LIBS = $(LIBFT) -lm -Lmlx -lmlx
MLXLINK = -framework OpenGL -framework Appkit
else ifeq ($(UNAME), Linux)
LIBS = $(LIBFT) -lm -Lmlx -lmlx_Linux
MLXLINK = -lXext -lX11
else
warning:
	@echo "Compilation for platform $(UNAME) not supported."
	exit 1
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBS) $(INCLUDE) $(MLXLINK) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
