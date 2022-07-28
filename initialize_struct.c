/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:26:51 by raho              #+#    #+#             */
/*   Updated: 2022/07/28 23:22:16 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_struct(t_node *tool)
{
	tool->mlx_ptr = NULL;
	tool->win_ptr = NULL;
	tool->img_ptr = NULL;
	tool->img_addr = NULL;
	tool->bits_per_pixel = 0;
	tool->size_line = 0;
	tool->endian = 0;
	tool->fractol = 0;
	tool->camera_x = 0;
	tool->camera_y = 0;
	reinitialize_struct(tool);
}

void	reinitialize_struct(t_node *tool)
{
	int	index;

	index = 0;
	while (index < WINDOW_SIZE_HEIGHT)
	{
		ft_bzero((void *)tool->iterationcounts[index], WINDOW_SIZE_WIDTH);
		ft_bzero((void *)tool->hue[index], WINDOW_SIZE_WIDTH);
		index++;
	}
	ft_bzero((void *)tool->numiterationsperpixel, MAX_ITERATIONS);
	tool->total = 0.0;
	tool->last_key = 0;
	tool->mouse_x = 0;
	tool->mouse_y = 0;
	tool->scale = 0;
}
