/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:15:40 by raho              #+#    #+#             */
/*   Updated: 2022/08/11 21:47:55 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	double	zi;
	double	zr;
	double	temp;
	int		iterations;

	zr = 0.0;
	zi = 0.0;
	iterations = 0;
	while ((((zr * zr) + (zi * zi)) <= 4.0) && iterations < MAX_ITERATIONS)
	{
		temp = zr * zr - zi * zi;
		zi = 2.0 * zr * zi + ci;
		zr = temp + cr;
		iterations++;
	}
	return (iterations);
}

int	julia(double cr, double ci, t_node *tool)
{
	double	zi;
	double	zr;
	double	temp;
	int		iterations;

	zr = cr;
	zi = ci;
	cr = -0.70176 + tool->mouse_x;
	ci = -0.3842 + tool->mouse_y;
	iterations = 0;
	while ((((zr * zr) + (zi * zi)) < 4.0) && iterations < MAX_ITERATIONS)
	{
		temp = zr * zr - zi * zi;
		zi = 2.0 * zr * zi + ci;
		zr = temp + cr;
		iterations++;
	}
	return (iterations);
}

int	burningship(double cr, double ci)
{
	double	zi;
	double	zr;
	double	temp;
	int		iterations;

	zr = cr;
	zi = ci;
	iterations = 0;
	while ((((zr * zr) + (zi * zi)) < 4.0) && iterations < MAX_ITERATIONS)
	{
		temp = zr * zr - zi * zi;
		zi = ft_fabs(2.0 * zr * zi) + ci;
		zr = temp + cr;
		iterations++;
	}
	return (iterations);
}
