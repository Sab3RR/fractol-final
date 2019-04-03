#include "fractol.h"

void	die(t_var *var)
{
	if (DIE.win_ptr && DIE.img_ptr)
	{
		mlx_destroy_image(MLX_PTR, IMG_PTR);
	}
	if (DIE.win_ptr)
	{
		mlx_destroy_window(MLX_PTR, WIN_PTR);
	}
	if (DIE.map)
	{
		free(var->map);
	}
	ft_putstr(REASON);
	free(var);
	exit(0);
}

void	put_pixel(t_var *var, int y, int x, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	*(int*)(var->img_addr + ((x + y * WIDTH) * var->bpp / 8)) = color;
}

void	warning(t_var *var)
{
	REASON = "Usage:\n"
			 	"./fractol mandelbrot|julia|burningship...\n"
	 				"            ...tricorn|multibrot|livebrot\n"
			 			"For multiple windows - type 2! fractal names:\n"
			 				"' ./fractol tricorn julia '  - for example\n"
			 					"Second window will be under the first one\n";
	die(var);
}



void	valid(t_var *var, char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		FRACTAL = MANDELBROT;
	else if (ft_strcmp(av, "julia") == 0)
		FRACTAL = JULIA;
	else if (ft_strcmp(av, "burningship") == 0)
		FRACTAL = BURNINGHSIP;
	else if (ft_strcmp(av, "tricorn") == 0)
		FRACTAL = TRICORN;
	else if (ft_strcmp(av, "multibrot") == 0)
		FRACTAL = MULTIBROT;
	else if (ft_strcmp(av, "livebrot") == 0)
		FRACTAL = LIVEBROT;
	else
	{
		warning(var);
	}
}

void	*debug_funct(t_var *var)
{
	int i;

	i = 0;
	while (1)
	{
		mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
		if (var->debug_var == P_THREADS)
		{
			while (i < P_THREADS)
				pthread_join(TID[i++], NULL);
			pthread_cancel(var->debug_tid[0]);
			break;
		}
	}
}

void	m_calc(t_var *var)
{
	B = X / ZOOM + R;
	Z_I = A;
	Z_R = B;
	ITERATOR = 0;
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
		put_pixel(VAR, Y, X, (0x02596D + ITERATOR * abs(COLOR)));
}

void	end_pthread(t_var *var)
{
	pthread_rwlock_wrlock(VAR->lock_rw);
	VAR->debug_var++;
	pthread_rwlock_unlock(VAR->lock_rw);
}

void	*mandelbrot(void *param)
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
			m_calc(var);
			X++;
		}
		Y++;
	}
	if (DEBUG == 1)
		end_pthread(var);
}

void	mandelbrot_fract(t_var var)
{
	int i;
	t_var	var1[P_THREADS];

	i = 0;
	ft_bzero(var.var->map, (size_t)(sizeof(char) * WIDTH * HEIGHT));
	ft_bzero(var.IMG_ADDR, (size_t)(WIDTH * HEIGHT * var.BPP / 8));
	while (i < P_THREADS)
	{
		var1[i] = var;
		pthread_create(&var.TID[i], NULL, mandelbrot, &var1[i]);
		i++;
	}
	if (var.DEBUG == 0)
	{
		i = 0;
		while (i < P_THREADS)
			pthread_join(var.TID[i++], NULL);
	}
	else
	{

		var.var->debug_var = 0;
		pthread_create(var.var->debug_tid, NULL, debug_funct, var.var);
		pthread_join(var.var->debug_tid[0], NULL);
	}

}

void	render(t_var *var)
{
	if (FRACTAL == MANDELBROT)
		mandelbrot_fract(*var);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}


void	ft_init(t_var *var)
{
	if (FRACTAL == MANDELBROT)
	{
		INIT5(ZOOM, 255, R, -3.84, I, -2.16, COLOR, 1, VAR, var);
		ITERATIONS = 50;
	}
	var->map = (char *)ft_memalloc(sizeof(char) * WIDTH * HEIGHT);
	render(var);
}

void	fractalgo(t_var *var, char *av)
{
	valid(var, av);
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIDTH, HEIGHT, "fractol 42");
	DIE.win_ptr = 1;
	IMG_PTR = mlx_new_image(MLX_PTR, WIDTH, HEIGHT);
	DIE.img_ptr = 1;
	BPP = 32;
	DEBUG = 1;
	IMG_ADDR = mlx_get_data_addr(IMG_PTR, &BPP, &SIZE_LINE, &ENDIAN);
	pthread_rwlock_init(var->lock_rw, NULL);
	pthread_mutex_init(var->mutex_tid, NULL);
	ft_init(var);
	mlx_loop(MLX_PTR);


}


int			main(int ac, char **av)
{
	t_var	*var;

	ac = 2;
	if (!(var = (t_var *)ft_memalloc(sizeof(t_var))))
		return (-1);
	if (ac == 2)
		fractalgo(var, "mandelbrot");
//	else if (ac == 3)
//		twofractalsgo(var, av);
//	else
//		warning(var);
	return (0);
}