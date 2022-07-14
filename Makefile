# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raho <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 18:17:08 by raho              #+#    #+#              #
#    Updated: 2022/05/23 19:31:29 by raho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LINUXMATH = -lm
LIBFTLIB = ./libft -lft
LIBFTINCL = ./libft
MLXLIB = /usr/local/lib
MLXINCL = /usr/local/include
FDFINCL = ./
SRCS = main.c do_events.c keybinds_0.c keybinds_1.c draw_selector.c\
		draw_mandelbrot.c draw_julia.c draw_burningship.c \
		image_pixel_put.c initialize_struct.c check_input.c
OBJS = $(SRCS:.c=.o)
MLXLINK = -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -L$(LIBFTLIB) -I$(LIBFTINCL) \
	$(LINUXMATH) -I$(MLXINCL) -I$(FDFINCL) $(MLXLINK) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
