#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
        void *mlx_ptr;
        void *win_ptr;
} t_data;


int	handle_no_event(void *data)
{
	(void)data;
	/*This function needs to exist, but it is useless for the moment*/
	return (0);
}

int	on_keypress(int key, t_data *mlx)
{
	printf("%d", key);
	if (key == XK_Escape)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}

int destroy_window(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data mlx;
	void *img;
	int height;
	int width;

	height = 256;
	width = 128;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 640, 480, "window");

	img = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/wizard.xpm", &height, &width);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img, 50, 50);


	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &on_keypress, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &destroy_window, &mlx);

	mlx_destroy_image(mlx.mlx_ptr, img);

	mlx_loop(mlx.mlx_ptr);
	
	mlx_destroy_display(mlx.mlx_ptr);

	free(mlx.mlx_ptr);
	return (0);
}

