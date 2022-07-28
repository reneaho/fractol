/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:59 by raho              #+#    #+#             */
/*   Updated: 2022/07/28 22:58:48 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static float	fractol_map(int value, float min1, float max1, float min2, float max2)
{
	float	a;
	float	b;
	float	c;
	float	res;

	a = value - min1;
	b = max1 - min1;
	c = max2 - min2;
	res = a / b * c + min2;
	return (res);
}

/*
float	calculate_camera(t_node *tool, float a)
{

}
*/

static void	calculate_iteration_counts(t_node *tool)
{
	int		pixelx;
	int		pixely;
	float	a;
	float	aa;
	float	b;
	float	bb;
	float	ca;
	float	cb;
	int		iterations;

	pixely = 0;
	while (pixely < WINDOW_SIZE_HEIGHT)
	{
		pixelx = 0;
		while (pixelx < WINDOW_SIZE_WIDTH)
		{
			a = fractol_map(pixelx, 0, WINDOW_SIZE_WIDTH, -2.00, 2.00);
			b = fractol_map(pixely, 0, WINDOW_SIZE_HEIGHT, -2.00, 2.00);
			ca = a + tool->camera_x;
			cb = b + tool->camera_y;
			a = 0;
			b = 0;
			iterations = 0;
			while (iterations < MAX_ITERATIONS)
			{
				aa = a * a - b * b;
				bb = 2.0 * a * b;
				a = aa + ca;
				b = bb + cb;
				if (ft_fabs(a + b) > 4.0)
					break ;
				iterations++;
			}
			tool->iterationcounts[pixely][pixelx] = iterations;
			pixelx++;
		}
		pixely++;
	}
}

static void	increment_index(t_node *tool)
{
	int	pixely;
	int	pixelx;
	int	index;

	pixely = 0;
	while (pixely < WINDOW_SIZE_HEIGHT)
	{
		pixelx = 0;
		while (pixelx < WINDOW_SIZE_WIDTH)
		{
			index = tool->iterationcounts[pixely][pixelx];
			tool->numiterationsperpixel[index]++;
			pixelx++;
		}
		pixely++;
	}
}

static void	add_up_save_total(t_node *tool)
{
	int	index;

	index = 0;
	while (index < MAX_ITERATIONS)
	{
		tool->total += tool->numiterationsperpixel[index];
		index++;
	}
}

static void	normalize(t_node *tool)
{
	int	pixely;
	int	pixelx;
	int	index;
	int	iteration;

	pixely = 0;
	while (pixely < WINDOW_SIZE_HEIGHT)
	{
		pixelx = 0;
		while (pixelx < WINDOW_SIZE_WIDTH)
		{
			iteration = tool->iterationcounts[pixely][pixelx];
			index = 0;
			while (index <= iteration)
			{
				tool->hue[pixely][pixelx] += (float)tool->numiterationsperpixel[index] / tool->total;
				index++;
			}
			pixelx++;
		}
		pixely++;
	}
}

void	draw_mandelbrot(t_node *tool)
{
	int		pixely;
	int		pixelx;
	float	color;
	float	a;
	float	aa;
	float	b;
	float	bb;
	float	ca;
	float	cb;
	int		iterations;

	calculate_iteration_counts(tool);	//histogram coloring first pass
	increment_index(tool);				//histogram coloring second pass
	add_up_save_total(tool);			//histogram coloring third pass
	normalize(tool);					//histogram coloring fourth pass	
	pixely = 0;
	while (pixely < WINDOW_SIZE_HEIGHT)
	{
		pixelx = 0;
		while (pixelx < WINDOW_SIZE_WIDTH)
		{
			a = fractol_map(pixelx, 0, WINDOW_SIZE_WIDTH, -2.00, 2.00);
			b = fractol_map(pixely, 0, WINDOW_SIZE_HEIGHT, -2.00, 2.00);
			ca = a + tool->camera_x;
			cb = b + tool->camera_y;
			a = 0;
			b = 0;
			iterations = 0;
			while (iterations < MAX_ITERATIONS)
			{
				aa = a * a - b * b;
				bb = 2.0 * a * b;
				a = aa + ca;
				b = bb + cb;
				if (ft_fabs(a + b) > 4.0)
					break ;
				iterations++;
			}
			if (iterations == MAX_ITERATIONS)
			{
				color = 0;
			}
			else
			{
				color = (int)tool->hue[pixely][pixelx];
			}
			image_pixel_put(tool, pixelx, pixely, color);
			pixelx++;
		}
		pixely++;	//lisaksi y+pos increment jos mappaa/skaalaa ulkopuolella sama x eli y_pos += y_scale. laskut tehdaan y_pos x_pos
	}
	mlx_put_image_to_window(tool->mlx_ptr, tool->win_ptr, \
											tool->img_ptr, 0, 0);
}
