#include "./minilibx-linux/mlx.h"
#include "./get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_collet
{
	int current;
	void *collect[6];
	void *current_collect;
} t_collet;

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
	void *player[4];
	void *player_current;
	char **map;
	int player_x;
	int player_y;
	t_collet collect;
	void *floor;
	void *wall;
	void *door;
}	t_data;

void	destroy_img(t_data mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.player[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.collect.collect[i]);
		i++;
	}
	mlx_destroy_image(mlx.mlx_ptr, mlx.floor);
	mlx_destroy_image(mlx.mlx_ptr, mlx.wall);
	mlx_destroy_image(mlx.mlx_ptr, mlx.door);
	i = 0;
	while (mlx.map[i])
	{
		free(mlx.map[i]);
		i++;
	}
	free(mlx.map);
}

int	destroy_window(t_data *mlx)
{
	destroy_img(*mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit(0);
	return (0);
}

/*
int	handle_no_event(void *data)
{
	(void)data;
	This function needs to exist, but it is useless for the moment
	return (0);
}*/

int	on_keypress(int key, t_data *mlx)
{
	static int move;

	if (key == XK_Escape)
	{
		/*
		int	i;

		i = 0;
		while (i < 4)
		{
			mlx_destroy_image(mlx->mlx_ptr, mlx->player[i]);
			i++;
		}
		i = 0;
		while (i < 6)
		{
			mlx_destroy_image(mlx->mlx_ptr, mlx->collect.collect[i]);
			i++;
		}
		mlx_destroy_image(mlx->mlx_ptr, mlx->wall);
		mlx_destroy_image(mlx->mlx_ptr, mlx->door);
		mlx_destroy_image(mlx->mlx_ptr, mlx->floor);
		*/
	//	destroy_img(*mlx);
		destroy_window(mlx);
	}
	else if (key == XK_Up && mlx->map[mlx->player_y - 1][mlx->player_x] != '1')
	{
		mlx->map[mlx->player_y][mlx->player_x] = '0';
		mlx->map[mlx->player_y - 1][mlx->player_x] = 'P';
		mlx->player_y = mlx->player_y - 1;
		mlx->player_current = mlx->player[3];
	}
	else if (key == XK_Down && mlx->map[mlx->player_y + 1][mlx->player_x] != '1')
	{
		mlx->map[mlx->player_y][mlx->player_x] = '0';
		mlx->map[mlx->player_y + 1][mlx->player_x] = 'P';
		mlx->player_y = mlx->player_y + 1;
		mlx->player_current = mlx->player[0];
	}
	else if (key == XK_Left && mlx->map[mlx->player_y][mlx->player_x - 1] != '1')
	{
		mlx->map[mlx->player_y][mlx->player_x] = '0';
		mlx->map[mlx->player_y][mlx->player_x - 1] = 'P';
		mlx->player_x = mlx->player_x - 1;
		mlx->player_current = mlx->player[1];
	}
	else if (key == XK_Right && mlx->map[mlx->player_y][mlx->player_x + 1] != '1')
	{
		mlx->map[mlx->player_y][mlx->player_x] = '0';
		mlx->map[mlx->player_y][mlx->player_x + 1] = 'P';
		mlx->player_x = mlx->player_x + 1;
		mlx->player_current = mlx->player[2];
		move++;
		printf("%d\n", move);
	}
	return (0);
}


void put_game(t_data mlx)
{
	int x;
	int y;

	y = 0;
//	mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
	while (mlx.map[y])
	{
		x = 0;
		while (mlx.map[y][x])
		{
			if (mlx.map[y][x] == '1')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.wall, x * 32, y * 48);
			else if (mlx.map[y][x] == 'P')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.player_current, x * 32, y * 48);
			else if (mlx.map[y][x] == 'C')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.collect.current_collect,  x * 32, y * 48);
			else if (mlx.map[y][x] == 'E')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.door,  x * 32, y * 48);
			else 
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.floor, x * 32, y * 48);
			x++;
		}
		y++;
	}
}

void	animation_collect(t_data mlx)
{
	static int current;

	if (current == 0)
	{
		mlx.collect.current_collect = mlx.collect.collect[0];
		printf("%d\n", current);
	}
	else if (current == 1 * 1000)
	{
		mlx.collect.current_collect = mlx.collect.collect[1];
	}
	else if (current == 2 * 1000)
	{
		mlx.collect.current_collect = mlx.collect.collect[2];
	}
	else if (current == 3 * 1000)
	{
		mlx.collect.current_collect = mlx.collect.collect[3];
	}
	else if (current == 4 * 1000)
	{
		mlx.collect.current_collect = mlx.collect.collect[4];
		current = 0;
	}
	current += 1;
}

int put_init(t_data *mlx)
{
	animation_collect(*mlx);
	put_game(*mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data mlx;
	int height;
	int width;
	int x;
	int y;
	char *line;
	int fd;
	int i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	mlx.map = (char **)malloc(sizeof(char *) * i);
	free(line);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		mlx.map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	mlx.map[i] = '\0';
	y = 0;
	while (mlx.map[y])
	{
		x = 0;
		while (mlx.map[y][x])
		{
			if (mlx.map[y][x] == 'P')
			{
				mlx.player_x = x;
				mlx.player_y = y;
			}
			if (mlx.map[y][x] == '\n')
				mlx.map[y][x] = '\0';
			x++;
		}
		y++;
	}
	close(fd);
	height = 48;
	width = 32;
	mlx.collect.current = 0;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, x * 32, y * 48, "window");

	mlx.collect.current = 0;
	mlx.collect.collect[0] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic1.xpm", &height, &width);
	mlx.collect.collect[1] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic2.xpm", &height, &width);
	mlx.collect.collect[2] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic3.xpm", &height, &width);
	mlx.collect.collect[3] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic4.xpm", &height, &width);
	mlx.collect.collect[4] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic5.xpm", &height, &width);
	mlx.collect.collect[5] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic6.xpm", &height, &width);


	mlx.door = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/door-close.xpm", &height, &width);
	mlx.wall = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/wall.xpm", &height, &width);
	mlx.floor = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/floor.xpm", &height, &width);
	mlx.player[0] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_front.xpm", &height, &width);
	mlx.player[1] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_left.xpm", &height, &width);
	mlx.player[2] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_right.xpm", &height, &width);
	mlx.player[3] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_back.xpm", &height, &width);
	mlx.player_current = mlx.player[0];
	mlx.collect.current_collect = mlx.collect.collect[0];

	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &on_keypress, &mlx);

	mlx_loop_hook(mlx.mlx_ptr, &put_init, (void *)&mlx);

	mlx_hook(mlx.win_ptr, 17, 0, &destroy_window, &mlx);
	mlx_loop(mlx.mlx_ptr);

	mlx_destroy_display(mlx.mlx_ptr);
/*
*/
	free(mlx.mlx_ptr);

	
/*	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.player[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.collect.collect[i]);
		i++;
	}
	mlx_destroy_image(mlx.mlx_ptr, mlx.floor);
	mlx_destroy_image(mlx.mlx_ptr, mlx.wall);



	mlx_loop(mlx.mlx_ptr);
	
	mlx_destroy_display(mlx.mlx_ptr);

	i = 0;
	while (mlx.map[i])
	{
		free(mlx.map[i]);
		i++;
	}
	free(mlx.map);

	free(mlx.mlx_ptr);*/
	return (0);
}

