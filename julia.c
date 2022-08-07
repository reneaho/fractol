/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:59 by raho              #+#    #+#             */
/*   Updated: 2022/08/07 22:10:16 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int x, int y, double a, t_node *tool)
{
	double	aa;
	double	b;
	double	bb;
	double	ca;
	double	cb;

	tool->iterations = 0;
	a = map_x(x);
	b = map_y(y);
	a = a * tool->scale + tool->camera_x;
	b = b * tool->scale + tool->camera_y;
	ca = -0.70176 + tool->mouse_x;
	cb = -0.3842 + tool->mouse_y;
	while (tool->iterations < MAX_ITERATIONS)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + ca;
		b = bb + cb;
		if (ft_fabs((a * a) + (b * b)) > 4)
			break ;
		tool->iterations++;
	}
}
