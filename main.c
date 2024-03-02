#include "./minilibx-linux/mlx.h"
#include "./get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_collect
{
	void	*collect[6];
	void	*current_collect;
	int		qtd_collect;
	int		*cord_x;
	int		*cord_y;
}	t_collect;

typedef	struct	s_player
{
	void	*player[4];
	int		player_x;
	int		player_y;
}	t_player;

typedef struct	s_map
{
	void	*floor;
	void	*wall;
	void	*door[2];
	void	*door_close_player[4];
	void	*current_door;
	int		x_door;
	int		y_door;
}	t_map;



typedef struct s_data
{
    void		*mlx_ptr;
    void		*win_ptr;
	void		*player_current;
	char		**map;
	t_collect	collect;
	t_player	player;
	t_map		maps;
}	t_data;

void	destroy_img(t_data mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.player.player[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.collect.collect[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx.mlx_ptr, mlx.maps.door_close_player[i]);
		i++;
	}
	mlx_destroy_image(mlx.mlx_ptr, mlx.maps.floor);
	mlx_destroy_image(mlx.mlx_ptr, mlx.maps.wall);
	mlx_destroy_image(mlx.mlx_ptr, mlx.maps.door[0]);
	mlx_destroy_image(mlx.mlx_ptr, mlx.maps.door[1]);
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
	free(mlx->collect.cord_x);
	free(mlx->collect.cord_y);
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
		destroy_window(mlx);
	}
	else if (key == XK_Up && mlx->map[mlx->player.player_y - 1][mlx->player.player_x] != '1')
	{	
		if (mlx->map[mlx->player.player_y - 1][mlx->player.player_x] == 'C')
			mlx->collect.qtd_collect--;
		if (mlx->map[mlx->player.player_y - 1][mlx->player.player_x] == 'E' && mlx->collect.qtd_collect == 0)
			destroy_window(mlx);
		if (mlx->map[mlx->player.player_y - 1][mlx->player.player_x] == 'E' && mlx->collect.qtd_collect != 0)
			mlx->player_current = mlx->maps.door_close_player[3];
		else
			mlx->player_current = mlx->player.player[3];
		if (mlx->maps.x_door == mlx->player.player_x && mlx->maps.y_door == mlx->player.player_y)
			mlx->map[mlx->player.player_y][mlx->player.player_x] = 'E';
		else
			mlx->map[mlx->player.player_y][mlx->player.player_x] = '0';
		mlx->map[mlx->player.player_y - 1][mlx->player.player_x] = 'P';
		mlx->player.player_y = mlx->player.player_y - 1;
	}
	else if (key == XK_Down && mlx->map[mlx->player.player_y + 1][mlx->player.player_x] != '1')
	{
		if (mlx->map[mlx->player.player_y + 1][mlx->player.player_x] == 'C')
			mlx->collect.qtd_collect--;
		if (mlx->map[mlx->player.player_y + 1][mlx->player.player_x] == 'E' && mlx->collect.qtd_collect == 0)
			destroy_window(mlx);
		if (mlx->map[mlx->player.player_y + 1][mlx->player.player_x] == 'E' && mlx->collect.qtd_collect != 0)
			mlx->player_current = mlx->maps.door_close_player[0];
		else
			mlx->player_current = mlx->player.player[0];
		if (mlx->maps.x_door == mlx->player.player_x && mlx->maps.y_door == mlx->player.player_y)
			mlx->map[mlx->player.player_y][mlx->player.player_x] = 'E';
		else
			mlx->map[mlx->player.player_y][mlx->player.player_x] = '0';


		mlx->map[mlx->player.player_y + 1][mlx->player.player_x] = 'P';
		mlx->player.player_y = mlx->player.player_y + 1;
	}
	else if (key == XK_Left && mlx->map[mlx->player.player_y][mlx->player.player_x - 1] != '1')
	{
		if (mlx->maps.x_door == mlx->player.player_x && mlx->maps.y_door == mlx->player.player_y)
			mlx->map[mlx->player.player_y][mlx->player.player_x] = 'E';
		if (mlx->map[mlx->player.player_y][mlx->player.player_x - 1] == 'C')
			mlx->collect.qtd_collect--;
		if (mlx->map[mlx->player.player_y][mlx->player.player_x - 1] == 'E'  && mlx->collect.qtd_collect == 0)
			destroy_window(mlx);

		if (mlx->map[mlx->player.player_y][mlx->player.player_x - 1] == 'E' && mlx->collect.qtd_collect != 0)
			mlx->player_current = mlx->maps.door_close_player[1];
		else
			mlx->player_current = mlx->player.player[1];
		if (mlx->maps.x_door == mlx->player.player_x && mlx->maps.y_door == mlx->player.player_y)
			mlx->map[mlx->player.player_y][mlx->player.player_x] = 'E';
		else
			mlx->map[mlx->player.player_y][mlx->player.player_x] = '0';


		mlx->map[mlx->player.player_y][mlx->player.player_x - 1] = 'P';
		mlx->player.player_x = mlx->player.player_x - 1;
	}
	else if (key == XK_Right && mlx->map[mlx->player.player_y][mlx->player.player_x + 1] != '1')
	{
		if (mlx->maps.x_door == mlx->player.player_x && mlx->maps.y_door == mlx->player.player_y)
			mlx->map[mlx->player.player_y][mlx->player.player_x] = 'E';
		if (mlx->map[mlx->player.player_y][mlx->player.player_x + 1] == 'C')
			mlx->collect.qtd_collect--;
		if (mlx->map[mlx->player.player_y][mlx->player.player_x + 1] == 'E' && mlx->collect.qtd_collect == 0)
			destroy_window(mlx);


		if (mlx->map[mlx->player.player_y][mlx->player.player_x + 1] == 'E' && mlx->collect.qtd_collect != 0)
			mlx->player_current = mlx->maps.door_close_player[2];
		else
			mlx->player_current = mlx->player.player[2];
		if (mlx->maps.x_door == mlx->player.player_x && mlx->maps.y_door == mlx->player.player_y)
			mlx->map[mlx->player.player_y][mlx->player.player_x] = 'E';
		else
			mlx->map[mlx->player.player_y][mlx->player.player_x] = '0';


		mlx->map[mlx->player.player_y][mlx->player.player_x + 1] = 'P';
		mlx->player.player_x = mlx->player.player_x + 1;
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
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.maps.wall, x * 32, y * 48);
			else if (mlx.map[y][x] == 'P')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.player_current, x * 32, y * 48);
			else if (mlx.map[y][x] == 'C')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.collect.current_collect,  x * 32, y * 48);
			else if (mlx.map[y][x] == 'E')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.maps.current_door,  x * 32, y * 48);
			else 
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.maps.floor, x * 32, y * 48);
			x++;
		}
		y++;
	}
}

void	animation_collect(t_data **mlx)
{
	static int i;
	static int frames;

	if (frames == 40)
	{
		(*mlx)->collect.current_collect = (*mlx)->collect.collect[i];
		i++;
		if (i == 5)
			i = 0;
		frames = 0;
	}
	frames++;
}

void if_door(t_data **mlx)
{
	if ((*mlx)->collect.qtd_collect == 0)
		(*mlx)->maps.current_door = (*mlx)->maps.door[1];
}

int put_init(t_data *mlx)
{
	if_door(&mlx);
	animation_collect(&mlx);
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
				mlx.player.player_x = x;
				mlx.player.player_y = y;
			}
			if (mlx.map[y][x] == 'E')
			{
				mlx.maps.x_door = x;
				mlx.maps.y_door = y;
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

	mlx.collect.qtd_collect = 0;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (x - 1) * 32, y * 48, "window");
	y = 0;
	while (mlx.map[y])
	{
		x = 0;
		while (mlx.map[y][x])
		{
			if (mlx.map[y][x] == 'C')
			{
				mlx.collect.qtd_collect++;
			}
			x++;
		}
		y++;
	}
	mlx.collect.cord_x = malloc(sizeof(int) * mlx.collect.qtd_collect);
	mlx.collect.cord_y = malloc(sizeof(int) * mlx.collect.qtd_collect);

	y = 0;
	i = 0;
	while (mlx.map[y])
	{
		x = 0;
		while (mlx.map[y][x])
		{
			if (mlx.map[y][x] == 'C')
			{
				mlx.collect.cord_x[i] = x;
				mlx.collect.cord_y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}

	mlx.collect.collect[0] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic1.xpm", &height, &width);
	mlx.collect.collect[1] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic2.xpm", &height, &width);
	mlx.collect.collect[2] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic3.xpm", &height, &width);
	mlx.collect.collect[3] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic4.xpm", &height, &width);
	mlx.collect.collect[4] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic5.xpm", &height, &width);
	mlx.collect.collect[5] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/magic6.xpm", &height, &width);


	mlx.maps.door_close_player[0] = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/door-close-front.xpm", &height, &width);
	mlx.maps.door_close_player[1] = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/door-close-left.xpm", &height, &width);
	mlx.maps.door_close_player[2] = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/door-close-right.xpm", &height, &width);
	mlx.maps.door_close_player[3] = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/door-close-back.xpm", &height, &width);

	mlx.maps.door[1] = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/door-open.xpm", &height, &width);
	mlx.maps.door[0] = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/door-close.xpm", &height, &width);
	mlx.maps.wall = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/wall.xpm", &height, &width);
	mlx.maps.floor = mlx_xpm_file_to_image(mlx.mlx_ptr,"./Wizard stay/floor.xpm", &height, &width);
	mlx.player.player[0] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_front.xpm", &height, &width);
	mlx.player.player[1] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_left.xpm", &height, &width);
	mlx.player.player[2] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_right.xpm", &height, &width);
	mlx.player.player[3] = mlx_xpm_file_to_image(mlx.mlx_ptr, "./Wizard stay/player_back.xpm", &height, &width);
	mlx.player_current = mlx.player.player[0];
	mlx.collect.current_collect = mlx.collect.collect[0];
	mlx.maps.current_door = mlx.maps.door[0];

	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &on_keypress, &mlx);

	mlx_loop_hook(mlx.mlx_ptr, &put_init, (void *)&mlx);

	mlx_hook(mlx.win_ptr, 17, 0, &destroy_window, &mlx);
	mlx_loop(mlx.mlx_ptr);

	mlx_destroy_display(mlx.mlx_ptr);


	free(mlx.mlx_ptr);
	return (0);
}

