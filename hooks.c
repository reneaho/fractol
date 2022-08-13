/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:02:28 by raho              #+#    #+#             */
/*   Updated: 2022/08/13 17:42:47 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_node *tool)
{
	mlx_destroy_image(tool->mlx_ptr, tool->img_ptr);
	mlx_destroy_window(tool->mlx_ptr, tool->win_ptr);
	exit (0);
}

void	key_press_helper(int key, t_node *tool)
{
	if (key == LINUX_A || key == MAC_A)
		tool->camera_x = tool->camera_x - 0.00055;
	else if (key == LINUX_D || key == MAC_D)
		tool->camera_x = tool->camera_x + 0.00055;
	else if (key == LINUX_W || key == MAC_W)
		tool->camera_y = tool->camera_y - 0.00055;
	else if (key == LINUX_S || key == MAC_S)
		tool->camera_y = tool->camera_y + 0.00055;
}

int	key_press(int key, void *param)
{
	t_node	*tool;

	tool = (t_node *)param;
	if (key == LINUX_LEFT || key == MAC_LEFT)
		tool->camera_x = tool->camera_x - 0.05;
	else if (key == LINUX_RIGHT || key == MAC_RIGHT)
		tool->camera_x = tool->camera_x + 0.05;
	else if (key == LINUX_UP || key == MAC_UP)
		tool->camera_y = tool->camera_y - 0.05;
	else if (key == LINUX_DOWN || key == MAC_DOWN)
		tool->camera_y = tool->camera_y + 0.05;
	else if (key == LINUX_ENTER || key == MAC_ENTER)
		reinitialize_struct(tool);
	else if (key == LINUX_ESC || key == MAC_ESC)
	{
		close_program(tool);
		exit (0);
	}
	else
		key_press_helper(key, tool);
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
	else if (button == LINUX_MOUSE_LEFT_CLICK || button == MAC_MOUSE_LEFT_CLICK)
	{
		if (tool->mouse_stop == 0)
			tool->mouse_stop = 1;
		else
			tool->mouse_stop = 0;
	}
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
		if (tool->mouse_stop == 1)
		{
			tool->mouse_x = map_real(x, -2, 2);
			tool->mouse_y = map_imaginary(y, -2, 2);
			erase_map(tool);
			draw_set(tool);
		}
	}
	return (0);
}
