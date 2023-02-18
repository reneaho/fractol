/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:44:02 by raho              #+#    #+#             */
/*   Updated: 2022/08/16 17:34:46 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_real(int x, double newmin, double newmax)
{
	double	oldmin;
	double	oldmax;
	double	temp;
	double	result;

	oldmin = 0;
	oldmax = WINDOW_SIZE_WIDTH;
	temp = (newmax - newmin) * (x - oldmin);
	result = (temp / (oldmax - oldmin)) + newmin;
	return (result);
}

double	map_imaginary(int y, double newmin, double newmax)
{
	double	oldmin;
	double	oldmax;
	double	temp;
	double	result;

	oldmin = 0;
	oldmax = WINDOW_SIZE_HEIGHT;
	temp = (newmax - newmin) * (y - oldmin);
	result = (temp / (oldmax - oldmin)) + newmin;
	return (result);
}

double	map_color(int iterations, double newmin, double newmax)
{
	double	oldmin;
	double	oldmax;
	double	temp;
	double	result;

	oldmin = 0;
	oldmax = MAX_ITERATIONS;
	temp = (newmax - newmin) * (iterations - oldmin);
	result = (temp / (oldmax - oldmin)) + newmin;
	return (result);
}
