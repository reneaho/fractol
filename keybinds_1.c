/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raho <raho@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:54:46 by raho              #+#    #+#             */
/*   Updated: 2022/07/18 14:25:34 by raho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keybinds_1(t_node *tool)
{
	if (tool->last_key == LINUX_ENTER || tool->last_key == MAC_ENTER)
	{
		erase_map(tool);
		reinitialize_struct(tool);
		draw_selector(tool);
	}
}
