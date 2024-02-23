#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>


typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;
/*
int	handle_no_event(void *data)
{
     This function needs to exist, but it is useless for the moment
    return (0);
}
*/
int	handle_input(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return (0);
}

int	main(void)
{
    t_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 480, "My first window!");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (1);
    }

    /* Setup hooks */ 
   /* mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);*/
    mlx_key_hook(data.win_ptr, &handle_input, &data);

    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}


/*
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;

int	on_keypress(int key, t_data *mlx)
{
	printf("%d", key);
	if (key == XK_Escape)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}

int	main(void)
{
	t_data mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 640, 480, "window");
	mlx_loop(mlx.mlx_ptr);

	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &on_keypress, &mlx);

	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
*/