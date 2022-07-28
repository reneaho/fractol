/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:59 by raho              #+#    #+#             */
/*   Updated: 2022/07/28 20:57:39 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	fractol_map(int value, int min1, int max1, double min2, double max2)
{
	double	a;
	double	b;
	double	c;
	double	res;

	a = (double)value - (double)min1;
	b = (double)max1 - (double)min1;
	c = max2 - min2;
	res = a / b * c + min2;
	return (res);
}

/*
float	calculate_camera(t_node *tool, float a)
{

}
*/
/*
static int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}
*/

void	draw_mandelbrot(t_node *tool)
{
	int		centerx;
	int		centery;
	int		pixelx;
	int		pixely;
	double	x;
	double	y;
	double	x0;
	double	y0;
	double	xtemp;
	int		iterations;
	int		maxiterations;
	int		color;
	double	breaktemp;

	centerx = WINDOW_SIZE_WIDTH / 2;
	centery = WINDOW_SIZE_HEIGHT / 2;
	maxiterations = 100;
	pixely = 0;
	while (pixely < WINDOW_SIZE_HEIGHT)
	{
		pixelx = 0;
		while (pixelx < WINDOW_SIZE_WIDTH)
		{
			x0 = (centerx + ((pixely / WINDOW_SIZE_WIDTH) - 0.5)) * tool->lengthx;
			y0 = (centery + ((pixelx / WINDOW_SIZE_WIDTH) - 0.5)) * tool->lengthy;
			x = 0.0 + tool->camera_x;
			y = 0.0 + tool->camera_y;
			iterations = 0;
			while (iterations < maxiterations)
			{
				xtemp = ((x * x) - (y * y)) + x0;
				y = ((2 * x) * y) + y0;
				x = xtemp;
				breaktemp = (x * x) + (y * y);
				iterations++;
				if (ft_fabs(breaktemp) > 4)
					break;
				
			}
			if (iterations == maxiterations)
				color = 0;
			else
				color = fractol_map(iterations, 0, maxiterations, 0, 255255255);
			//color = plot(iteration);
			image_pixel_put(tool, pixelx, pixely, color);
			pixelx++;
		}
		pixely++;	//lisaksi y+pos increment jos mappaa/skaalaa ulkopuolella sama x eli y_pos += y_scale. laskut tehdaan y_pos x_pos
	}
	mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
											tool->img_ptr, 0, 0);
}
