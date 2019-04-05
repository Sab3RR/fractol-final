#include "fractol.h"

void	*debug_funct(t_var *var)
{
	int i;

	i = 0;
	while (1)
	{
//		mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
		if (var->debug_var == P_THREADS)
		{
//			pthread_rwlock_wrlock(var->core);
			while (i < P_THREADS)
			{
				if (var->core_tid[i] == 1)
				{
					var->core_tid[i] = 0;
					pthread_join(TID[i++], NULL);
				}
			}
//			pthread_rwlock_unlock(var->core);
			pthread_exit(NULL);
		}
	}
}

void	end_pthread(t_var *var)
{
	pthread_testcancel();
	pthread_rwlock_wrlock(VAR->lock_rw);
	VAR->debug_var++;
	pthread_rwlock_unlock(VAR->lock_rw);
}