/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:55 by raho              #+#    #+#             */
/*   Updated: 2022/09/19 19:06:34 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage_exit(void)
{
	ft_putendl_fd("usage: ./fractol <fractal>", 2);
	ft_putendl_fd("fractals:", 2);
	ft_putendl_fd("Mandelbrot", 2);
	ft_putendl_fd("Julia", 2);
	ft_putendl_fd("BurningShip", 2);
	exit (1);
}

static int	check_input(char *fractal, t_node *tool)
{
	if (ft_strequ(fractal, "Mandelbrot") == 1)
		tool->fractal = 1;
	else if (ft_strequ(fractal, "Julia") == 1)
		tool->fractal = 2;
	else if (ft_strequ(fractal, "BurningShip") == 1)
		tool->fractal = 3;
	else
		return (-1);
	return (0);
}

static int	initialize_mlx(t_node *tool)
{
	tool->mlx_ptr = mlx_init();
	if (tool->mlx_ptr == NULL)
		return (-1);
	tool->win_ptr = mlx_new_window(tool->mlx_ptr, \
					WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT, "fractol");
	if (tool->win_ptr == NULL)
		return (-1);
	tool->img_ptr = mlx_new_image(tool->mlx_ptr, \
					WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	if (tool->img_ptr == NULL)
		return (-1);
	tool->img_addr = mlx_get_data_addr(tool->img_ptr, &tool->bits_per_pixel, \
											&tool->size_line, &tool->endian);
	if (tool->img_ptr == NULL)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		result;
	t_node	tool;

	initialize_struct(&tool);
	if (argc == 2)
		result = check_input(argv[1], &tool);
	if (argc != 2 || result == -1)
		print_usage_exit();
	if (initialize_mlx(&tool) == -1)
	{
		ft_putendl_fd("mlx error", 2);
		return (1);
	}
	draw_set(&tool);
	mlx_hook(tool.win_ptr, 2, 1L << 0, key_press, (void *)&tool);
	mlx_hook(tool.win_ptr, 4, 1L << 2, mouse_click, (void *)&tool);
	if (tool.fractal == 2)
		mlx_hook(tool.win_ptr, 6, 1L << 6, mouse_hover, (void *)&tool);
	mlx_hook(tool.win_ptr, 17, 0, close_program, (void *)&tool);
	mlx_loop(tool.mlx_ptr);
	return (0);
}
