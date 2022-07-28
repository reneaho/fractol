/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:54:46 by raho              #+#    #+#             */
/*   Updated: 2022/07/28 23:22:30 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keybinds_1(t_node *tool)
{
	if (tool->last_key == LINUX_ENTER || tool->last_key == MAC_ENTER)
	{
		erase_map(tool);
		reinitialize_struct(tool);
		tool->camera_x = 0;
		tool->camera_y = 0;
		draw_selector(tool);
	}
}
