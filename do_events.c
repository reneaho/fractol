/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:02:28 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 17:03:41 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_keybinds(void)
{
	ft_putendl("ENTER - Resets the map");
	ft_putendl("ESC - Quit the program");
}

static int	key_press(int key, void *param)
{
	t_node		*tool;

	tool = (t_node *)param;
	tool->last_key = key;
	keybinds_0(tool);
	return (0);
}

static int	mouse_click(int mouse_button, int x, int y, void *param)
{
	t_node	*tool;

	tool = (t_node *)param;
	tool->last_key = mouse_button;
	ft_putstr("mouse_button:");
	ft_putnbr(mouse_button);
	ft_putchar('\n');
	ft_putstr("x:");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("y:");
	ft_putnbr(y);
	ft_putchar('\n');
	keybinds_0(tool);
	return (0);
}

static int	mouse_hover(t_node *tool)
{
	int	x;
	int	y;

	x = tool->mouse_x;
	y = tool->mouse_y;
	mlx_mouse_get_pos(tool->mlx_ptr, tool->win_ptr, \
						&tool->mouse_x, &tool->mouse_y);
	if ((x != tool->mouse_x || y != tool->mouse_y) && \
			(tool->mouse_x >= 0 && tool->mouse_x <= WINDOW_SIZE_WIDTH && \
			tool->mouse_y >= 0 && tool->mouse_y <= WINDOW_SIZE_HEIGHT))
	{
		ft_putstr("x:");
		ft_putnbr(tool->mouse_x);
		ft_putchar('\n');
		ft_putstr("y:");
		ft_putnbr(tool->mouse_y);
		ft_putchar('\n');
	}
	return (0);
}

void	do_events(t_node *tool)
{
	tool->mlx_ptr = mlx_init();
	tool->win_ptr = mlx_new_window(tool->mlx_ptr, \
					WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, "fdf");
	tool->img_ptr = mlx_new_image(tool->mlx_ptr, \
					WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	tool->img_addr = mlx_get_data_addr(tool->img_ptr, &tool->bits_per_pixel, \
											&tool->size_line, &tool->endian);
	draw_selector(tool);
	print_keybinds();
	mlx_key_hook(tool->win_ptr, key_press, (void *)tool);
	mlx_mouse_hook(tool->win_ptr, mouse_click, (void *)tool);
	mlx_loop_hook(tool->mlx_ptr, mouse_hover, (void *)tool);
	mlx_loop(tool->mlx_ptr);
}
