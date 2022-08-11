/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:27 by raho              #+#    #+#             */
/*   Updated: 2022/08/11 21:58:47 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WINDOW_SIZE_WIDTH 800
# define WINDOW_SIZE_HEIGHT 800
# define MAX_ITERATIONS 100
# define LINUX_LEFT 65361
# define LINUX_UP 65362
# define LINUX_RIGHT 65363
# define LINUX_DOWN 65364
# define LINUX_W 119
# define LINUX_A 97
# define LINUX_S 115
# define LINUX_D 100
# define LINUX_ENTER 65293
# define LINUX_ESC 65307
# define LINUX_MOUSE_WHEEL_UP 4
# define LINUX_MOUSE_WHEEL_DOWN 5
# define LINUX_MOUSE_LEFT_CLICK 1
# define LINUX_MOUSE_RIGHT_CLICK 2
# define MAC_LEFT 123
# define MAC_UP 126
# define MAC_RIGHT 124
# define MAC_DOWN 125
# define MAC_W 13
# define MAC_A 0
# define MAC_S 1
# define MAC_D 2
# define MAC_ENTER 36
# define MAC_ESC 53
# define MAC_MOUSE_WHEEL_UP 4
# define MAC_MOUSE_WHEEL_DOWN 5
# define MAC_MOUSE_LEFT_CLICK 1
# define MAC_MOUSE_RIGHT_CLICK 2

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_node
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		fractal;
	double	camera_x;
	double	camera_y;
	double	mouse_x;
	double	mouse_y;
	double	scale;
}		t_node;

void	initialize_struct(t_node *tool);
void	reinitialize_struct(t_node *tool);
void	image_pixel_put(int color, int x, int y, t_node *tool);
void	draw_set(t_node *tool);
int		mandelbrot(double cr, double ci);
int		julia(double cr, double ci, t_node *tool);
int		burningship(double cr, double ci);
int		key_press(int key, void *param);
int		mouse_click(int mouse_button, int x, int y, void *param);
int		mouse_hover(int x, int y, void *param);
double	map_real(int x, double newmin, double newmax);
double	map_imaginary(int y, double newmin, double newmax);
double	map_color(int iterations, double newmin, double newmax);
void	erase_map(t_node *tool);
int		close_program(t_node *tool);

#endif
