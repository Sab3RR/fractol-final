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

void	ft_init(t_var *var)
{
	int i;

	i = -1;
	if (FRACTAL == MANDELBROT)
	{
		INIT5(ZOOM, 255, R, -3.84, I, -2.16, COLOR, 1, VAR, var);
		ITERATIONS = 500;
		while (++i < P_THREADS)
			var->st_var[i] = (t_var*)ft_memalloc(sizeof(t_var));
	}
	COLOR = 1;
	DEBUG = 1;
	var->map = (char*)ft_memalloc(WIDTH * HEIGHT);
	pthread_rwlock_wrlock(var->render);
	pthread_create(var->render_tid, NULL, render, var);
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
	pthread_attr_init(var->attr);
//	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	pthread_rwlock_init(var->lock_rw, NULL);
	pthread_rwlock_init(var->render, NULL);
//	pthread_mutex_init(var->mutex_tid, NULL);
	ft_init(var);
	mlx_loop_hook(var->mlx_ptr, loop_hook, (void*)var);
	mlx_hook(WIN_PTR, MOUSEPRESSED, (1L << 17), mousepressed, var);
//	mlx_hook(WIN_PTR, KEYPRESSED, (1L << 17), keypressed, var);
	mlx_loop(MLX_PTR);
}

