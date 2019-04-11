#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# define WIDTH 420
# define HEIGHT 420

# define KEYPRESSED 2
# define KEYRELEASED 3
# define MOUSEPRESSED 4
# define MOSUERELEASED 5
# define MOUSEMOVED 6
# define REDBUTTONPRESSED 17

# define ESC 53
# define PLUS 69
# define MINUS 78
# define LEFT 123
# define RIGTH 124
# define DOWN 125
# define UP 126
# define RESETSPACE 49
# define LEFTMOUSE 1
# define RIGHTMOUSE 2
# define WHEELUP 4
# define WHEELDOWN 5
# define POWUP 116
# define POWDOWN 121
# define F 3
# define SCL 33
# define SCR 30

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
# define FREEZEJULIA var->f_julia

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
	int 				*filter;
	char 				f_julia;
	char				loopf;
	char 				br;
	char 				*reason;
	char 				debug;
	char 				core_tid[P_THREADS];
	pthread_rwlock_t	*lock_map;
	pthread_attr_t		attr[1];
	pthread_t			tid[P_THREADS];
	t_die				die;
	struct s_var		*var;

}						t_var;

int 					keypressed(int key, void *param);
void					tricorn_fract(t_var var);
void					burningship_fract(t_var var);
void					julia_fract(t_var var);
void					put_pixel(t_var *var, int y, int x, int color);
int						julia_mouse(int x, int y, void *param);
void					fractalgo(t_var *var, char *av);
void					render(t_var *var);
int 					mousepressed(int button, int x, int y, void *param);
#endif
