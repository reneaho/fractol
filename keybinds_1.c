#include "fractol.h"

void	keybinds_1(t_node *tool)
{
	if (tool->last_key == LINUX_ESC || tool->last_key == MAC_ESC)
		tool->last_key = 0;
}
