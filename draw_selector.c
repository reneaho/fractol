#include "fractol.h"

void    draw_selector(t_node *tool)
{
    if (tool->fractol == 1)
        draw_mandelbrot(tool);
    if (tool->fractol == 2)
        draw_julia(tool);
    if (tool->fractol == 3)
        draw_burningship(tool);
}
