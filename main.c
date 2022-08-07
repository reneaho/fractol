/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:55 by raho              #+#    #+#             */
/*   Updated: 2022/08/07 21:42:57 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage_exit(void)
{
	ft_putendl("usage: ./fractol <fractol>");
	ft_putendl("fractols:");
	ft_putendl("Mandelbrot");
	ft_putendl("Julia");
	ft_putendl("Burning Ship");
	exit (0);
}

static int	check_input(int argc, char *argv[], t_node *tool)
{
	if (argc == 2)
		return (check_argc_2(argv[1], tool));
	else
		return (check_argc_3(argv, tool));
}

int	main(int argc, char *argv[])
{
	int		res;
	t_node	tool;

	initialize_struct(&tool);
	if (argc == 2 || argc == 3)
		res = check_input(argc, argv, &tool);
	if (argc < 2 || res == -1)
		usage_exit();
	tool.mlx_ptr = mlx_init();
	tool.win_ptr = mlx_new_window(tool.mlx_ptr, \
					WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, "fractol");
	tool.img_ptr = mlx_new_image(tool.mlx_ptr, \
					WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	tool.img_addr = mlx_get_data_addr(tool.img_ptr, &tool.bits_per_pixel, \
											&tool.size_line, &tool.endian);
	draw_set(&tool);
	mlx_hook(tool.win_ptr, 2, 1L << 0, key_press, (void *)&tool);
	mlx_hook(tool.win_ptr, 4, 1L << 2, mouse_click, (void *)&tool);
	if (tool.fractol == 2)
		mlx_hook(tool.win_ptr, 6, 1L << 6, mouse_hover, (void *)&tool);
	mlx_loop(tool.mlx_ptr);
	return (0);
}
