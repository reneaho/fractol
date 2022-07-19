# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raho <raho@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:17:08 by raho              #+#    #+#              #
#    Updated: 2022/07/18 14:15:58 by raho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFTLIB = ./libft -lft
LIBFTINCL = ./libft
MLXLIB = /usr/local/lib
MLXINCL = /usr/local/include
FDFINCL = ./
SRCS = main.c do_events.c keybinds_0.c keybinds_1.c draw_selector.c\
		draw_mandelbrot.c draw_julia.c draw_burningship.c \
		image_pixel_put.c initialize_struct.c check_input.c
OBJS = $(SRCS:.c=.o)
MLXLINK = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	cd libft; make all
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTLIB) -I$(LIBFTINCL) -I$(MLXINCL) \
	-I$(FDFINCL) $(MLXLINK) -o $(NAME)

clean:
	cd libft; make clean
	rm -f $(OBJS)

fclean: clean
	cd libft; make fclean
	rm -f $(NAME)

re: fclean all
	cd libft; make re
