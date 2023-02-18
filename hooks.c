/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:02:28 by raho              #+#    #+#             */
/*   Updated: 2022/09/04 20:54:07 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(t_node *tool)
{
	mlx_destroy_image(tool->mlx_ptr, tool->img_ptr);
	mlx_destroy_window(tool->mlx_ptr, tool->win_ptr);
	exit (0);
}

int	key_press(int key, void *param)
{
	t_node	*tool;

	tool = (t_node *)param;
	if (key == LINUX_LEFT || key == MAC_LEFT)
		tool->camera_x -= 0.05 * tool->scale;
	else if (key == LINUX_RIGHT || key == MAC_RIGHT)
		tool->camera_x += 0.05 * tool->scale;
	else if (key == LINUX_UP || key == MAC_UP)
		tool->camera_y -= 0.05 * tool->scale;
	else if (key == LINUX_DOWN || key == MAC_DOWN)
		tool->camera_y += 0.05 * tool->scale;
	else if (key == LINUX_ENTER || key == MAC_ENTER)
		reinitialize_struct(tool);
	else if (key == LINUX_ESC || key == MAC_ESC)
		close_program(tool);
	mlx_clear_window(tool->mlx_ptr, tool->win_ptr);
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
	mlx_clear_window(tool->mlx_ptr, tool->win_ptr);
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
			mlx_clear_window(tool->mlx_ptr, tool->win_ptr);
			draw_set(tool);
		}
	}
	return (0);
}
