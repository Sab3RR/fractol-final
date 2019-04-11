#include "fractol.h"

void	die(void *param)
{
	t_var *var;

	var = (t_var *)param;
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
			 "./fractol mandelbrot|julia|burningship|tricorn\n"
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
	else
	{
		warning(var);
	}
}

void	ft_init(t_var *var)
{
	int i;

	i = -1;
//	if (FRACTAL == MANDELBROT || FRACTAL == BURNINGHSIP || FRACTAL == TRICORN)
//	{
//		INIT5(ZOOM, 255, R, -3.84, I, -2.16, COLOR, 1, VAR, var);

//	}
	if (FRACTAL == JULIA)
	{
		INIT5(ZOOM, 1, R, -4.5, I, -2.5, COLOR, 1, VAR, var);
		B = 0.285;
		A = 0.1;
	}
	INIT5(ZOOM, 80, R, -2.5, I, -2.5, COLOR, 1, VAR, var);
	ITERATIONS = 20;
	COLOR = 1000;
	var->map = (char*)ft_memalloc(WIDTH * HEIGHT);
	render(var);
}

void	fractalgo(t_var *var, char *av)
{
	int	i;

	valid(var, av);
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIDTH, HEIGHT, "fractol 42");
	DIE.win_ptr = 1;
	IMG_PTR = mlx_new_image(MLX_PTR, WIDTH, HEIGHT);
	DIE.img_ptr = 1;
	BPP = 32;
	DEBUG = 1;
	IMG_ADDR = mlx_get_data_addr(IMG_PTR, &BPP, &SIZE_LINE, &ENDIAN);
	var->lock_map = (pthread_rwlock_t*)malloc(sizeof(pthread_rwlock_t) * WIDTH * HEIGHT);
	i = -1;
	while (++i < WIDTH * HEIGHT)
		pthread_rwlock_init(&var->lock_map[i], NULL);
	ft_init(var);
//	mlx_loop_hook(var->mlx_ptr, loop_hook, (void*)var);
	mlx_hook(WIN_PTR, 6, 1L < 17, julia_mouse, var);
	mlx_hook(WIN_PTR, MOUSEPRESSED, (1L << 17), mousepressed, var);
	mlx_hook(WIN_PTR, KEYPRESSED, (1L << 17), keypressed, var);
	mlx_hook(WIN_PTR, REDBUTTONPRESSED, (1L << 17), die, var);
	mlx_loop(MLX_PTR);
}

