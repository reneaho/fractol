/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:55 by raho              #+#    #+#             */
/*   Updated: 2022/05/26 18:43:51 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void usage_exit(void)
{
    ft_putendl("usage: ./fractol <fractol>");
    ft_putendl("fractols:");
    ft_putendl("Mandelbrot");
    ft_putendl("Julia");
    ft_putendl("Third");
    exit (0);
}

int	main(int argc, char *argv[])
{
	t_node	tool;

	if (argc == 2)
	{
        initialize_struct(&tool);
        if (check_input(&tool, argv[1]))
            do_events(&tool);
        else
            usage_exit();
	}
	else
		usage_exit();
	//free_all(&tool);
	return (0);
}
