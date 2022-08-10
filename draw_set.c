/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:20:23 by raho              #+#    #+#             */
/*   Updated: 2022/08/11 00:27:52 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_pixel_put(int color, int x, int y, t_node *tool)
{
	char	*pixel;

	pixel = tool->img_addr + (y * tool->size_line + x * \
								(tool->bits_per_pixel / 8));
	*(int *)pixel = color;
}

static int	color_repeater(int color)
{
	int	temp;

	temp = color;
	if (color > 0)
	{
		color = color * 1000;
		color = color + temp;
		color = color * 1000;
		color = color + temp;
	}
	else if (color < 0)
	{
		color = color * 1000;
		color = color - temp;
		color = color * 1000;
		color = color - temp;
	}
	return (color);
}

static int	set_color(int iterations)
{
	int	color;

	if (iterations == MAX_ITERATIONS)
		color = 0;
	else
	{
		color = (int)map_color(iterations);
		color = color_repeater(color);
	}
	return (color);
}

static int	select_fractal(double cr, double ci, t_node *tool)
{
	if (tool->fractol == 1)
		return (mandelbrot(cr, ci));
	else if (tool->fractol == 2)
		return (julia(cr, ci, tool));
	else
		return (burningship(cr, ci));
}

void	draw_set(t_node *tool)
{
	int		x;
	int		y;
	int		iterations;
	double	cr;
	double	ci;

	y = 0;
	while (y < WINDOW_SIZE_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_SIZE_WIDTH)
		{
			cr = map_real(x);
			ci = map_imaginary(y);
			cr = cr * tool->scale + tool->camera_x;
			ci = ci * tool->scale + tool->camera_y;
			iterations = select_fractal(cr, ci, tool);
			image_pixel_put(set_color(iterations), x, y, tool);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
											tool->img_ptr, 0, 0);
}
