#include "fractol.h"

int loop_hook(void *param)
{
	t_var *var;

	var = (t_var *)param;
	if (DEBUG)
	{
		mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	}
}


int mousepressed(int button, int x, int y, void *param)
{
	int i;
	t_var *var;

	var = (t_var *)param;
	if (button == 4)
	{
//		var->x1 = (x / var->zoom + var->x1) - (x / (var->zoom * 1.2));
//		var->y1 = (y / var->zoom + var->y1) - (y / (var->zoom * 1.2));
//		var->zoom *= 1.2;
		R = (x / ZOOM + R) - (x / (ZOOM * 1.2));
		I = (y / ZOOM + I) - (y / (ZOOM * 1.2));
		ZOOM *= 1.2;
		if (pthread_rwlock_trywrlock(var->render) == 0)
			pthread_create(var->render_tid, NULL, render, var);
		else
		{
			i = -1;
			pthread_rwlock_wrlock(var->core);
			while (++i < P_THREADS)
			{
				if (var->core_tid[i] == 1)
				{
					pthread_cancel(var->tid[i]);
				}
			}
			pthread_rwlock_wrlock(var->lock_rw);
			var->debug_var = 4;
			pthread_join(var->debug_tid[0], NULL);
			pthread_cancel(var->render_tid[0]);
			pthread_join(var->tid[i], NULL);
			pthread_rwlock_unlock(var->core);
			pthread_rwlock_unlock(var->lock_rw);
			var->debug_var = P_THREADS;
			pthread_create(var->render_tid, NULL, render, var);
		}
	}
	if (button == 5)
	{
		R = (x / ZOOM + R) - (x / (ZOOM / 1.2));
		I = (y / ZOOM + I) - (y / (ZOOM / 1.2));
		ZOOM /= 1.2;
		if (pthread_rwlock_trywrlock(var->render) == 0)
			pthread_create(var->render_tid, NULL, render, var);
		else
		{
			i = -1;
			pthread_rwlock_wrlock(var->core);
			while (++i < P_THREADS)
			{
				if (var->core_tid[i] == 1)
				{
					pthread_cancel(var->tid[i]);
				}
			}
			pthread_rwlock_wrlock(var->lock_rw);
			var->debug_var = 4;
			pthread_join(var->debug_tid[0], NULL);
			pthread_cancel(var->render_tid[0]);
			pthread_join(var->tid[i], NULL);
			pthread_rwlock_unlock(var->core);
			pthread_rwlock_unlock(var->lock_rw);
			var->debug_var = P_THREADS;
			pthread_create(var->render_tid, NULL, render, var);
		}
	}
}
