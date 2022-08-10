/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 00:15:40 by raho              #+#    #+#             */
/*   Updated: 2022/08/11 00:50:59 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	double	zi;
	double	zr;
	double	temp;
	int		iterations;

	iterations = 0;
	zr = cr;
	zi = ci;
	while (iterations < MAX_ITERATIONS)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		if (ft_fabs((zr * zr) + (zi * zi)) > 4.0)
			break ;
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

	iterations = 0;
	zr = cr;
	zi = ci;
	cr = -0.70176 + tool->mouse_x;
	ci = -0.3842 + tool->mouse_y;
	while (iterations < MAX_ITERATIONS)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		if (ft_fabs((zr * zr) + (zi * zi)) > 4.0)
			break ;
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

	iterations = 0;
	zi = ci;
	zr = cr;
	while (iterations < MAX_ITERATIONS)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * ft_fabs(zr * zi) + ci;
		zr = temp;
		if (ft_fabs((zr * zr) + (zi * zi)) > 4.0)
			break ;
		iterations++;
	}
	return (iterations);
}
