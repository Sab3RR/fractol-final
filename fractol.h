#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# define WIDTH 1920
# define HEIGHT 1080

# define KEYPRESSED 2
# define KEYRELEASED 3
# define MOUSEPRESSED 4
# define MOSUERELEASED 5
# define MOUSEMOVED 6
# define REDBUTTONPRESSED 17

# define P_THREADS 4

# define FRACTAL var->fractal
# define REASON var->reason
# define WIN_PTR var->win_ptr
# define MLX_PTR var->mlx_ptr
# define IMG_PTR var->img_ptr
# define IMG_ADDR var->img_addr
# define BPP var->bpp
# define SIZE_LINE var->size_line
# define ENDIAN var->endian
# define DIE var->die
# define ZOOM var->zoom
# define R var->r
# define I var->i
# define Y var->y
# define X var->x
# define A var->a
# define B var->b
# define Z_I var->z_i
# define Z_R var->z_r
# define ITERATOR var->iterator
# define ITERATIONS var->iterations
# define SQRT Z_R * Z_R + Z_I * Z_I < 4
# define IF_FULL ITERATOR < ITERATIONS
# define IF_EQUAL ITERATOR == ITERATIONS
# define VAR var->var
# define COLOR var->color
# define Z_R_TMP var->z_r_tmp
# define Z_I_TMP var->z_i_tmp
# define IS_FREE VAR->map[X + Y * WIDTH]
# define TID var->tid
# define DEBUG var->debug

# define MANDELBROT 0
# define JULIA 1
# define BURNINGHSIP 2
# define TRICORN 3
# define MULTIBROT 4
# define LIVEBROT 5

# define INIT5(a, b, c, d, e, f, g, h, i, j) a = b; c = d; e = f; g = h; i = j;
# define INIT4(a, b, c, d, e, f, g, h) a = b; c = d; e = f; g = h;
# define INIT3(a, b, c, d, e, f) a = b; c = d; e = f;

typedef struct			s_die
{
	char				win_ptr;
	char				img_ptr;
	char				map;
}						t_die;

typedef struct			s_var
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img_addr;
	int					bpp;
	int					size_line;
	int					endian;
	int 				iterations;
	int 				iterator;
	int 				x;
	int 				y;
	int 				color;
	int 				debug_var;
	int					fractal;
	long double			zoom;
	long double			a;
	long double			b;
	long double			z_r;
	long double			z_i;
	long double			z_r_tmp;
	long double			z_i_tmp;
	long double 		r;
	long double 		i;
	char 				*map;
	char				loopf;
	char 				br;
	char 				*reason;
	char 				debug;
	pthread_t			tid[P_THREADS];
	pthread_rwlock_t	lock_rw[1];
	pthread_mutex_t		mutex_tid[1];
	pthread_t 			debug_tid[1];
	t_die				die;
	struct s_var		*var;

}						t_var;
#endif
