#include "fractol.h"

void	b_calc(t_var *var)
{
	B = X / ZOOM + R;
	Z_I = A;
	Z_R = B;
	ITERATOR = 0;
	while (IF_FULL && SQRT)
	{
		Z_R_TMP = Z_R * Z_R - Z_I * Z_I + B;
		Z_I_TMP = fabsl(2 * Z_R * Z_I) + A;
		Z_R = Z_R_TMP;
		Z_I = Z_I_TMP;
		ITERATOR++;
	}
	if (IF_EQUAL)
		put_pixel(VAR, Y, X, 0x000000);
	else
		put_pixel(VAR, Y, X, ((ITERATOR + 1) * abs(COLOR)));
}


void	*burningship(void *param)
{
	t_var *var;

	var = (t_var*)param;
	Y = 0;
	while (Y < HEIGHT)
	{
		A = Y / ZOOM + I;
		X = 0;
		while (X < WIDTH)
		{
			if (IS_FREE)
			{
				X++;
				continue;
			}
			else
				VAR->map[X + Y * WIDTH] = 1;
			b_calc(var);
			X++;
		}
		Y++;
	}
	return (0);
}

void	burningship_fract(t_var var)
{
	int i = 0;
	t_var	var1[P_THREADS];

	i = 0;
	ft_bzero(var.var->map, (size_t)(sizeof(char) * WIDTH * HEIGHT));
	ft_bzero(var.IMG_ADDR, (size_t)(WIDTH * HEIGHT * var.BPP / 8));
	while (i < P_THREADS)
	{

		var1[i] = var;
		pthread_create(&var.TID[i], NULL, burningship, &var1[i]);
		i++;
	}
	i = 0;
	while (i < P_THREADS)
	{
		pthread_join(var.TID[i++], NULL);
	}

}

