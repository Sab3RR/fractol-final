#include "fractol.h"


int			main(int ac, char **av)
{
	t_var	*var;

	ac = 2;
	if (!(var = (t_var *)ft_memalloc(sizeof(t_var))))
		return (-1);
	if (ac == 2)
		fractalgo(var, "julia");
//	else if (ac == 3)
//		twofractalsgo(var, av);
//	else
//		warning(var);
	return (0);
}