/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:54:29 by raho              #+#    #+#             */
/*   Updated: 2022/08/11 21:55:45 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	erase_map(t_node *tool)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_SIZE_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_SIZE_WIDTH)
		{
			image_pixel_put(0x000000, x, y, tool);
			x++;
		}
		y++;
	}
}

void	image_pixel_put(int color, int x, int y, t_node *tool)
{
	char	*pixel;

	pixel = tool->img_addr + ((y * tool->size_line) + (x * \
								(tool->bits_per_pixel / 8)));
	*(int *)pixel = color;
}
