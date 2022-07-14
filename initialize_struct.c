/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:26:51 by raho              #+#    #+#             */
/*   Updated: 2022/05/26 18:31:05 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_struct(t_node *tool)
{
	tool->mlx_ptr = NULL;
	tool->win_ptr = NULL;
	tool->img_ptr = NULL;
	tool->img_addr = NULL;
	tool->bits_per_pixel = 0;
	tool->size_line = 0;
	tool->endian = 0;
	tool->last_key = 0;
	tool->fractol = 0;
	tool->mouse_x = 0;
	tool->mouse_y = 0;
	tool->scale = 0;
	tool->camera_x = 0;
	tool->camera_y = 0;
	//reinitialize_struct(tool);
}

/*
void	reinitialize_struct(t_node *tool)
{
	
}
*/