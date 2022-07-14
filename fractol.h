/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:27 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:57:50 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WINDOW_SIZE_WIDTH 1000
# define WINDOW_SIZE_HEIGHT 1000
# define MAP_START_TILE_WIDTH 64
# define MAP_START_TILE_HEIGHT 64
# define MAP_START_TILE_DEPTH 10
# define MAP_START_POSITION_WIDTH 0
# define MAP_START_POSITION_HEIGHT 0
# define COLOR_NEUTRAL 0xFFFFFF
# define COLOR_POSITIVE 0xD154E4
# define COLOR_NEGATIVE 0xF51911
# define COLOR_TRANSITION 0xF9D460
# define LINUX_W 119
# define LINUX_A 97
# define LINUX_S 115
# define LINUX_D 100
# define LINUX_Q 113
# define LINUX_E 101
# define LINUX_I 105
# define LINUX_J 106
# define LINUX_K 107
# define LINUX_L 108
# define LINUX_U 117
# define LINUX_O 111
# define LINUX_LEFT 65361
# define LINUX_UP 65362
# define LINUX_RIGHT 65363
# define LINUX_DOWN 65364
# define LINUX_ENTER 65293
# define LINUX_ESC 65307
# define LINUX_MOUSE_WHEEL_UP 4
# define LINUX_MOUSE_WHEEL_DOWN 5
# define MAC_W 13
# define MAC_A 0
# define MAC_S 1
# define MAC_D 2
# define MAC_Q 12
# define MAC_E 14
# define MAC_I 34
# define MAC_J 38
# define MAC_K 40
# define MAC_L 37
# define MAC_U 32
# define MAC_O 31
# define MAC_LEFT 123
# define MAC_UP 126
# define MAC_RIGHT 124
# define MAC_DOWN 125
# define MAC_ENTER 036
# define MAC_ESC 53
# define MAC_MOUSE_WHEEL_UP 1000
# define MAC_MOUSE_WHEEL_DOWN 1000

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_node
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		last_key;
	int		fractol;
	int		mouse_x;
	int		mouse_y;
	float	scale;
	float	camera_x;
	float	camera_y;
}		t_node;

int		check_input_1(t_node *tool, char *fractol);
int		check_input_2(t_node *tool, char *fractol[]);
void	initialize_struct(t_node *tool);
void	do_events(t_node *tool);
void	draw_line(t_node *tool, int color);
void	image_pixel_put(t_node *tool, int x, int y, int color);
int		check_if_inside(int x, int y);
void    draw_selector(t_node *tool);
void	draw_mandelbrot(t_node *tool);
void	draw_julia(t_node *tool);
void	draw_burningship(t_node *tool);
void	erase_map(t_node *tool);
void	keybinds_0(t_node *tool);
void	keybinds_1(t_node *tool);
//void	reinitialize_struct(t_node *tool);
void	free_all(t_node *tool);

#endif
