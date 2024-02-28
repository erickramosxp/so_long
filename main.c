#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
	void *player[4];
	void *floor;
	void *wall;
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
	int height;
	int width;
	int x;
	int y;

	height = 48;
	width = 32;

	y = 0;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 640, 480, "window");

	mlx.wall = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/wall.xpm", &height, &width);
	mlx.floor = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/floor.xpm", &height, &width);
	mlx.player[0] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_front.xpm", &height, &width);
	mlx.player[1] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_left.xpm", &height, &width);
	mlx.player[2] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_right.xpm", &height, &width);
	mlx.player[3] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_back.xpm", &height, &width);
//	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.player[0], 32, 0);
	while (y <= 480)
	{
		x = 0;
		while (x <= 640)
		{
			if (x== 0 || y == 0 || x == 608 || y == 432)
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.wall, x, y);
			else 
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.floor, x, y);
			x += 32;
		}
		y += 48;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.player[0], 32, 48);

	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &on_keypress, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &destroy_window, &mlx);
	int i;
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.player[i]);
		i++;
	}
	mlx_destroy_image(mlx.mlx_ptr, mlx.floor);
	mlx_destroy_image(mlx.mlx_ptr, mlx.wall);

	mlx_loop(mlx.mlx_ptr);
	
	mlx_destroy_display(mlx.mlx_ptr);

	free(mlx.mlx_ptr);
	return (0);
}

