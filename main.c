#include "./minilibx-linux/mlx.h"
#include <stdlib.h>

int	main(void)
{
	void *mlx;
	void *w_mlx;

	mlx = mlx_init();
	w_mlx = mlx_new_window(mlx, 640, 480, "window");
	mlx_loop(mlx);
	free(mlx);
	return (0);
}