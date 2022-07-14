/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:55 by raho              #+#    #+#             */
/*   Updated: 2022/06/17 16:54:36 by raho             ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_node	tool;

	initialize_struct(&tool);
	if (argc == 2)
	{
		if (check_input_1(&tool, argv[1]))
			do_events(&tool);
		else
			usage_exit();
	}
	else if (argc == 3)
	{
		if (check_input_2(&tool, argv))
			do_events(&tool);
		else
			usage_exit();
	}
	else
		usage_exit();
	return (0);
}
