/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:55 by raho              #+#    #+#             */
/*   Updated: 2022/09/04 20:35:33 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage_exit(void)
{
	ft_putendl_fd("usage: ./fractol <fractol>", 2);
	ft_putendl_fd("fractols:", 2);
	ft_putendl_fd("Mandelbrot", 2);
	ft_putendl_fd("Julia", 2);
	ft_putendl_fd("Burning Ship", 2);
	exit (1);
}

static int	check_argc_2(char *fractal, t_node *tool)
{
	if (ft_strequ(fractal, "Mandelbrot") == 1)
		tool->fractal = 1;
	else if (ft_strequ(fractal, "Julia") == 1)
		tool->fractal = 2;
	else
		return (-1);
	return (0);
}

static int	check_argc_3(char *fractal[], t_node *tool)
{
	if (ft_strequ(fractal[1], "Burning") == 1)
	{
		if (ft_strequ(fractal[2], "Ship") == 1)
			tool->fractal = 3;
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
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
	int		result;
	t_node	tool;

	initialize_struct(&tool);
	if (argc == 2 || argc == 3)
		result = check_input(argc, argv, &tool);
	if (argc < 2 || argc > 3 || result == -1)
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
	if (tool.fractal == 2)
		mlx_hook(tool.win_ptr, 6, 1L << 6, mouse_hover, (void *)&tool);
	mlx_hook(tool.win_ptr, 17, 0, close_program, (void *)&tool);
	mlx_loop(tool.mlx_ptr);
	return (0);
}
