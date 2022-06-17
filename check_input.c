#include "fractol.h"

static void set_str_mandelbrot(char *str)
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

static void set_str_julia(char *str)
{
    str[0] = 'J';
    str[1] = 'u';
    str[2] = 'l';
    str[3] = 'i';
    str[4] = 'a';
    str[5] = '\0';
}

static void set_str_third(char *str)
{
    str[0] = 'T';
    str[1] = 'h';
    str[2] = 'i';
    str[3] = 'r';
    str[4] = 'd';
    str[5] = '\0';
}

int  check_input(t_node *tool, char *fractol)
{
    char    mandelbrot[11];
    char    julia[6];
    char    third[6];

    set_str_mandelbrot(mandelbrot);
    set_str_julia(julia);
    set_str_third(third);
    if (ft_strequ(fractol, mandelbrot) == 1)
        tool->fractol = 1;
    else if (ft_strequ(fractol, julia) == 1)
        tool->fractol = 2;
    else if (ft_strequ(fractol, third) == 1)
        tool->fractol = 3;
    else
        return (0);
    return (1);
}
