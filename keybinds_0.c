/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:56:09 by raho              #+#    #+#             */
/*   Updated: 2022/07/22 18:28:50 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_program(t_node *tool)
{
	mlx_destroy_image(tool->mlx_ptr, tool->img_ptr);
	mlx_destroy_window(tool->mlx_ptr, tool->win_ptr);
	//free_all(tool);
	exit (0);
}

void	erase_map(t_node *tool)
{
	int	x;
	int	y;

	y = 0;
	while (y <= WINDOW_SIZE_HEIGHT)
	{
		x = 0;
		while (x <= WINDOW_SIZE_WIDTH)
		{
			image_pixel_put(tool, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	print_values(t_node *tool)
{
	printf("camera_x: %f\ncamera_y: %f\nscale: %f\n", tool->camera_x, tool->camera_y, tool->scale);
}

void	keybinds_0(t_node *tool)
{
	if (tool->last_key == LINUX_LEFT || \
			tool->last_key == MAC_LEFT)
	{
		tool->camera_x = tool->camera_x - 0.1;
		erase_map(tool);
		draw_selector(tool);
	}
	if (tool->last_key == LINUX_RIGHT || \
			tool->last_key == MAC_RIGHT)
	{
		tool->camera_x = tool->camera_x + 0.1;
		erase_map(tool);
		draw_selector(tool);
	}
	if (tool->last_key == LINUX_UP || \
			tool->last_key == MAC_UP)
	{
		tool->camera_y = tool->camera_y - 0.1;
		erase_map(tool);
		draw_selector(tool);
	}
	if (tool->last_key == LINUX_DOWN || \
			tool->last_key == MAC_DOWN)
	{
		tool->camera_y = tool->camera_y + 0.1;
		erase_map(tool);
		draw_selector(tool);
	}
	if (tool->last_key == LINUX_MOUSE_WHEEL_UP || \
			tool->last_key == MAC_MOUSE_WHEEL_UP)
	{
		tool->scale = tool->scale - 0.1;
		erase_map(tool);
		draw_selector(tool);
	}
	if (tool->last_key == LINUX_MOUSE_WHEEL_DOWN || \
			tool->last_key == MAC_MOUSE_WHEEL_DOWN)
	{
		tool->scale = tool->scale + 0.1;
		erase_map(tool);
		draw_selector(tool);
	}
	if (tool->last_key == LINUX_ESC || tool->last_key == MAC_ESC)
		close_program(tool);
	keybinds_1(tool);
	print_values(tool);
	ft_putchar('\n');
}
