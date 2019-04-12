#include "fractol.h"


int			main(int ac, char **av)
{
	char *avv[2] = {"mandelbrot", "julia"};
	t_var	*var;

	ac = 3;
	if (!(var = (t_var *)ft_memalloc(sizeof(t_var))))
		return (-1);
	if (ac == 2)
		fractalgo(var, "julia");
	else if (ac == 3)
		twofractalsgo(var, avv);
	else
		warning(var);
	return (0);
}