/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:44:02 by raho              #+#    #+#             */
/*   Updated: 2022/08/07 22:13:01 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_x(int x)
{
	double	slope;
	double	output;

	slope = 1.0 * (2 - (-2)) / (WINDOW_SIZE_WIDTH - 0);
	output = -2 + slope * (x - 0);
	return (output);
}

double	map_y(int y)
{
	double	slope;
	double	output;

	slope = 1.0 * (2 - (-2)) / (WINDOW_SIZE_HEIGHT - 0);
	output = -2 + slope * (y - 0);
	return (output);
}

double	map_color(int iterations)
{
	double	slope;
	double	output;

	slope = 1.0 * (255 - 1) / (MAX_ITERATIONS - 0);
	output = 1 + slope * (iterations - 0);
	return (output);
}
