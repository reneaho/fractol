#include "fractol.h"

static void	close_program(t_node *tool)
{
	mlx_destroy_image(tool->mlx_ptr, tool->img_ptr);
	mlx_destroy_window(tool->mlx_ptr, tool->win_ptr);
	//free_all(tool);
	exit (0);
}

void erase_map(t_node *tool)
{
	int	x;
	int	y;

	y = 0;
	while (y <= WINDOW_SIZE_HEIGHT)
	{
		x = 0;
		while (x <= WINDOW_SIZE_WIDTH)
		{
			image_pixel_put(tool, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void    keybinds_0(t_node *tool)
{
	if (tool->last_key == LINUX_W || tool->last_key == MAC_W)
	{
		erase_map(tool);
		draw_mandelbrot(tool);
	}
	if (tool->last_key == LINUX_ESC || tool->last_key == MAC_ESC)
		close_program(tool);
	//keybinds_1(tool);
}
