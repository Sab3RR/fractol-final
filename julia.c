#include "fractol.h"

int		julia_mouse(int x, int y, void *param)
{
	t_var *var;

	var = (t_var*)param;
	if (FRACTAL == JULIA && !FREEZEJULIA)
	{
		B = x * 2;
		A = y * 2 - 800;
		render(var);
	}
	return (0);
}

void	j_calc(t_var *var)
{
	Z_R = X / ZOOM + R;
	var->z_i = var->y /var->zoom + var->i;
	ITERATOR = 0;
	while (IF_FULL && SQRT)
	{
//		Z_R_TMP = Z_R * Z_R - Z_I * Z_I + B;
//		Z_I_TMP = 2 * Z_R * Z_I + A;
//		Z_R = Z_R_TMP;
//		Z_I = Z_I_TMP;
//		Z_R_TMP = Z_R * Z_R - Z_I * Z_I - 0.8 + (B / WIDTH);
//		Z_I_TMP = 2 * Z_R * Z_I + A / WIDTH;
//		Z_I = Z_I_TMP;
//		Z_R = Z_R_TMP;
		var->z_r_tmp = var->z_r;
		var->z_r = var->z_r * var->z_r - var->z_i * var->z_i - 0.8 + (var->b / WIDTH);
		var->z_i = 2 * var->z_i * var->z_r_tmp + var->a / WIDTH;
		ITERATOR++;
	}
	if (IF_EQUAL)
		put_pixel(VAR, Y, X, 0x000000);
	else
		put_pixel(VAR, Y, X, ((ITERATOR + 1) * abs(COLOR)));
}

void	*julia(void *param)
{
	t_var *var;

	var = (t_var*)param;
	Y = 0;
	while (Y < HEIGHT)
	{
		Z_I = Y / ZOOM + I;
		X = 0;
		while (X < WIDTH)
		{
			pthread_rwlock_wrlock(&var->var->lock_map[X + Y * WIDTH]);
			if (IS_FREE)
			{
				pthread_rwlock_unlock(&var->var->lock_map[X + Y * WIDTH]);
				X++;
				continue;
			}
			else
				VAR->map[X + Y * WIDTH] = 1;
			pthread_rwlock_unlock(&var->var->lock_map[X + Y * WIDTH]);
			j_calc(var);
			X++;
		}
		Y++;
	}
	return (0);
}

void	julia_fract(t_var var)
{
	int i = 0;
	t_var	var1[P_THREADS];

	i = 0;
	ft_bzero(var.var->map, (size_t)(sizeof(char) * WIDTH * HEIGHT));
	ft_bzero(var.IMG_ADDR, (size_t)(WIDTH * HEIGHT * var.BPP / 8));
	while (i < P_THREADS)
	{

		var1[i] = var;
		pthread_create(&var.TID[i], NULL, julia, &var1[i]);
		i++;
	}
	i = 0;
	while (i < P_THREADS)
	{
		pthread_join(var.TID[i++], NULL);
	}
}