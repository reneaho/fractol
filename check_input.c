/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:05:05 by raho              #+#    #+#             */
/*   Updated: 2022/08/07 21:47:34 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_str_mandelbrot(char *str)
{
	str[0] = 'M';
	str[1] = 'a';
	str[2] = 'n';
	str[3] = 'd';
	str[4] = 'e';
	str[5] = 'l';
	str[6] = 'b';
	str[7] = 'r';
	str[8] = 'o';
	str[9] = 't';
	str[10] = '\0';
}

static void	set_str_julia(char *str)
{
	str[0] = 'J';
	str[1] = 'u';
	str[2] = 'l';
	str[3] = 'i';
	str[4] = 'a';
	str[5] = '\0';
}

static void	set_str_burningship(char *str1, char *str2)
{
	str1[0] = 'B';
	str1[1] = 'u';
	str1[2] = 'r';
	str1[3] = 'n';
	str1[4] = 'i';
	str1[5] = 'n';
	str1[6] = 'g';
	str1[7] = '\0';
	str2[0] = 'S';
	str2[1] = 'h';
	str2[2] = 'i';
	str2[3] = 'p';
	str2[4] = '\0';
}

int	check_argc_2(char *fractol, t_node *tool)
{
	char	mandelbrot[11];
	char	julia[6];

	set_str_mandelbrot(mandelbrot);
	set_str_julia(julia);
	if (ft_strequ(fractol, mandelbrot) == 1)
		tool->fractol = 1;
	else if (ft_strequ(fractol, julia) == 1)
		tool->fractol = 2;
	else
		return (-1);
	return (0);
}

int	check_argc_3(char *fractol[], t_node *tool)
{
	char	burning[8];
	char	ship[5];

	set_str_burningship(burning, ship);
	if (ft_strequ(burning, fractol[1]) == 1)
	{
		if (ft_strequ(ship, fractol[2]) == 1)
		{
			tool->fractol = 3;
			return (0);
		}
	}
	return (-1);
}
