/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:57:05 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:57:20 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_pixel_put(t_node *tool, int x, int y, int color)
{
	char	*pixel;

	pixel = tool->img_addr + (y * tool->size_line + x * \
								(tool->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int	check_if_inside(int x, int y)
{
	if ((x >= 0 && x < WINDOW_SIZE_WIDTH) && (y >= 0 && y < WINDOW_SIZE_HEIGHT))
		return (1);
	else
		return (0);
}
