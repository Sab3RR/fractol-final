#include "fractol.h"

void	put_pixel(t_var *var, int y, int x, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int*)(var->img_addr + ((x + y * WIDTH) * var->bpp / 8)) = color;
}

void	m_calc(t_var *var)
{
	B = X / ZOOM + R;
	Z_I = A;
	Z_R = B;
	ITERATOR = 0;
	pthread_testcancel();
	while (IF_FULL && SQRT)
	{
		Z_R_TMP = Z_R * Z_R - Z_I * Z_I + B;
		Z_I_TMP = 2 * Z_R * Z_I + A;
		Z_R = Z_R_TMP;
		Z_I = Z_I_TMP;
		ITERATOR++;
	}
	if (IF_EQUAL)
		put_pixel(VAR, Y, X, 0x000000);
	else
		put_pixel(VAR, Y, X, (0x02596D * (ITERATOR + 1) * abs(COLOR)));
}


void	*mandelbrot(void *param)
{
	t_var *var;

	var = (t_var*)param;
//	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	Y = 0;
	while (Y < HEIGHT)
	{
		A = Y / ZOOM + I;
		X = 0;
		while (X < WIDTH)
		{
			if (IS_FREE)
			{
				pthread_testcancel();
				X++;
				continue;
			}
			else
				VAR->map[X + Y * WIDTH] = 1;
			m_calc(var);
			X++;
		}
		Y++;
	}
	if (DEBUG == 1)
		end_pthread(var);
	pthread_exit(NULL);
}

void	mandelbrot_fract(t_var var)
{
	int i = 0;

	i = 0;
//	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	ft_bzero(var.var->map, (size_t)(sizeof(char) * WIDTH * HEIGHT));
	ft_bzero(var.IMG_ADDR, (size_t)(WIDTH * HEIGHT * var.BPP / 8));
	pthread_testcancel();
	pthread_rwlock_wrlock(var.var->core);
	while (i < P_THREADS)
	{

		ft_memcpy(var.st_var[i], &var, sizeof(t_var));
		pthread_create(&var.TID[i], NULL, mandelbrot, var.st_var[i]);
		var.var->core_tid[i] = 1;
		i++;
	}
	pthread_rwlock_unlock(var.var->core);
	if (var.DEBUG == 0)
	{
		i = 0;
		while (i < P_THREADS)
		{
			var.var->core_tid[i] = 0;
			pthread_join(var.TID[i++], NULL);
		}
	}
	else
	{

		var.var->debug_var = 0;
		pthread_create(var.var->debug_tid, NULL, debug_funct, var.var);
		pthread_join(var.var->debug_tid[0], NULL);
	}
}

void	*render(void *param)
{
	t_var *var;

	var = (t_var*)param;
	if (FRACTAL == MANDELBROT)
		mandelbrot_fract(*var);
	pthread_rwlock_unlock(var->render);
	pthread_exit(NULL);
//	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

