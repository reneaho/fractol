/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:02:28 by raho              #+#    #+#             */
/*   Updated: 2022/08/10 23:25:27 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_program(t_node *tool)
{
	mlx_destroy_image(tool->mlx_ptr, tool->img_ptr);
	mlx_destroy_window(tool->mlx_ptr, tool->win_ptr);
	exit (0);
}

static void	erase_map(t_node *tool)
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

int	key_press(int key, void *param)
{
	t_node	*tool;

	tool = (t_node *)param;
	if (key == LINUX_LEFT || key == MAC_LEFT)
		tool->camera_x = tool->camera_x - 0.1;
	else if (key == LINUX_RIGHT || key == MAC_RIGHT)
		tool->camera_x = tool->camera_x + 0.1;
	else if (key == LINUX_UP || key == MAC_UP)
		tool->camera_y = tool->camera_y - 0.1;
	else if (key == LINUX_DOWN || key == MAC_DOWN)
		tool->camera_y = tool->camera_y + 0.1;
	else if (key == LINUX_ENTER || key == MAC_ENTER)
		reinitialize_struct(tool);
	else if (key == LINUX_ESC || key == MAC_ESC)
		close_program(tool);
	erase_map(tool);
	draw_set(tool);
	return (0);
}

int	mouse_click(int button, int x, int y, void *param)
{
	t_node	*tool;

	(void)x;
	(void)y;
	tool = (t_node *)param;
	if (button == LINUX_MOUSE_WHEEL_UP || button == MAC_MOUSE_WHEEL_UP)
		tool->scale = tool->scale * 0.9;
	else if (button == LINUX_MOUSE_WHEEL_DOWN || button == MAC_MOUSE_WHEEL_DOWN)
		tool->scale = tool->scale * 1.1;
	erase_map(tool);
	draw_set(tool);
	return (0);
}

int	mouse_hover(int x, int y, void *param)
{
	t_node	*tool;

	tool = (t_node *)param;
	if ((x >= 0 && x < WINDOW_SIZE_WIDTH) && (y >= 0 && y < WINDOW_SIZE_HEIGHT))
	{
		tool->mouse_x = map_real(x);
		tool->mouse_y = map_imaginary(y);
		erase_map(tool);
		draw_set(tool);
	}
	return (0);
}
