#include "fractol.h"

void	*new_fractal(void *param)
{
	t_var	*var;

	var = (t_var*)param;

	if (FRACTAL == MANDELBROT)
		fractalgo(var, "mandelbrot");
	else if (FRACTAL == JULIA)
		fractalgo(var, "julia");
	else if (FRACTAL == BURNINGHSIP)
		fractalgo(var, "burningship");
	else if (FRACTAL == TRICORN)
		fractalgo(var, "tricorn");
	return (0);
}

void	twofractalsgo(t_var *var, char **av)
{
	int i;

	valid(var, av[0]);
	valid(var, av[1]);
	i = fork();
	if (i == 0)
		fractalgo(var, av[0]);
	else
		fractalgo(var, av[1]);
}