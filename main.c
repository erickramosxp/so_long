#include "./minilibx-linux/mlx.h"
#include "./minilibx-linux/mlx_int.h"
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
	int			x;
	int			y;
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
void	condition_move_player(t_data **mlx, int x, int y)
{
	if ((*mlx)->map[(*mlx)->player.player_y + y][(*mlx)->player.player_x + x] == 'E' && (*mlx)->collect.qtd_collect == 0)
		destroy_window(*mlx);
	if ((*mlx)->map[(*mlx)->player.player_y + y][(*mlx)->player.player_x + x] == 'C')
		(*mlx)->collect.qtd_collect--;
	if ((*mlx)->maps.x_door == (*mlx)->player.player_x && (*mlx)->maps.y_door == (*mlx)->player.player_y)
		(*mlx)->map[(*mlx)->player.player_y][(*mlx)->player.player_x] = 'E';
	else
		(*mlx)->map[(*mlx)->player.player_y][(*mlx)->player.player_x] = '0';
}

void	move_player(t_data **mlx, int x, int y, int index)
{
	if ((*mlx)->map[(*mlx)->player.player_y + y][(*mlx)->player.player_x + x] == 'E' && (*mlx)->collect.qtd_collect != 0)
	(*mlx)->player_current = (*mlx)->maps.door_close_player[index];
	else
		(*mlx)->player_current = (*mlx)->player.player[index];
	(*mlx)->map[(*mlx)->player.player_y + y][(*mlx)->player.player_x + x] = 'P';
	if (y == 0)
		(*mlx)->player.player_x = (*mlx)->player.player_x + x;
	else
		(*mlx)->player.player_y = (*mlx)->player.player_y + y;
}

int	on_keypress(int key, t_data *mlx)
{
	static int	move;

	if (key == XK_Escape)
		destroy_window(mlx);
	else if (key == XK_Up && mlx->map[mlx->player.player_y - 1][mlx->player.player_x] != '1')
	{	
		condition_move_player(&mlx, 0, -1);
		move_player(&mlx, 0, -1, 3);
	}
	else if (key == XK_Down && mlx->map[mlx->player.player_y + 1][mlx->player.player_x] != '1')
	{
		condition_move_player(&mlx, 0, +1);
		move_player(&mlx, 0, +1, 0);
	}
	else if (key == XK_Left && mlx->map[mlx->player.player_y][mlx->player.player_x - 1] != '1')
	{
		condition_move_player(&mlx, -1, 0);
		move_player(&mlx, -1, 0, 1);
	}
	else if (key == XK_Right && mlx->map[mlx->player.player_y][mlx->player.player_x + 1] != '1')
	{
		condition_move_player(&mlx, +1, 0);
		move_player(&mlx, +1, 0, 2);
		move++;
	}
	return (0);
}


void put_game(t_data mlx)
{
	int	x;
	int	y;

	y = 0;
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
	static int	i;
	static int	frames;

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

void	if_door(t_data **mlx)
{
	if ((*mlx)->collect.qtd_collect == 0)
		(*mlx)->maps.current_door = (*mlx)->maps.door[1];
}

int	put_init(t_data *mlx)
{
	if_door(&mlx);
	animation_collect(&mlx);
	put_game(*mlx);
	return (1);
}

void	*load_xpm(t_data mlx, char *src)
{
	void	*img;
	int		height;
	int		width;

	img = mlx_xpm_file_to_image(mlx.mlx_ptr, src, &height, &width);
	return (img);
}

void	get_img_collect(t_data *mlx)
{
	mlx->collect.collect[0] = load_xpm(*mlx, "./Wizard stay/magic1.xpm");
	mlx->collect.collect[1] = load_xpm(*mlx, "./Wizard stay/magic2.xpm");
	mlx->collect.collect[2] = load_xpm(*mlx, "./Wizard stay/magic3.xpm");
	mlx->collect.collect[3] = load_xpm(*mlx, "./Wizard stay/magic4.xpm");
	mlx->collect.collect[4] = load_xpm(*mlx, "./Wizard stay/magic5.xpm");
	mlx->collect.collect[5] = load_xpm(*mlx, "./Wizard stay/magic6.xpm");
}

void	get_img_map(t_data *mlx)
{
	mlx->maps.door[1] = load_xpm(*mlx, "./Wizard stay/door-open.xpm");
	mlx->maps.door[0] = load_xpm(*mlx, "./Wizard stay/door-close.xpm");
	mlx->maps.wall = load_xpm(*mlx, "./Wizard stay/wall.xpm");
	mlx->maps.floor = load_xpm(*mlx, "./Wizard stay/floor.xpm");
	mlx->maps.door_close_player[0] = load_xpm(*mlx,
			"./Wizard stay/door-close-front.xpm");
	mlx->maps.door_close_player[1] = load_xpm(*mlx,
			"./Wizard stay/door-close-left.xpm");
	mlx->maps.door_close_player[2] = load_xpm(*mlx,
			"./Wizard stay/door-close-right.xpm");
	mlx->maps.door_close_player[3] = load_xpm(*mlx,
			"./Wizard stay/door-close-back.xpm");
}

void	get_img_player(t_data *mlx)
{
	mlx->player.player[0] = load_xpm(*mlx, "./Wizard stay/player_front.xpm");
	mlx->player.player[1] = load_xpm(*mlx, "./Wizard stay/player_left.xpm");
	mlx->player.player[2] = load_xpm(*mlx, "./Wizard stay/player_right.xpm");
	mlx->player.player[3] = load_xpm(*mlx, "./Wizard stay/player_back.xpm");
}

void	get_img(t_data *mlx)
{
	get_img_collect(mlx);
	get_img_map(mlx);
	get_img_player(mlx);
}

int	get_qtd_line(char **argv)
{
	int		i;
	char	*line;
	int		fd;

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
	return (i);
}

void	get_map(t_data *mlx, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	i = get_qtd_line(argv);
	mlx->map = (char **)malloc(sizeof(char *) * i);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		mlx->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	mlx->map[i] = '\0';
}

void	get_positions(t_data *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'P')
			{
				mlx->player.player_x = x;
				mlx->player.player_y = y;
			}
			if (mlx->map[y][x] == 'E')
			{
				mlx->maps.x_door = x;
				mlx->maps.y_door = y;
			}
			if (mlx->map[y][x] == '\n')
				mlx->map[y][x] = '\0';
			x++;
		}
		y++;
	}
}

void	get_x_and_y(t_data *mlx)
{
	mlx->y = 0;
	mlx->collect.qtd_collect = 0;
	while (mlx->map[mlx->y])
	{
		mlx->x = 0;
		while (mlx->map[mlx->y][mlx->x])
		{
			if (mlx->map[mlx->y][mlx->x] == 'C')
			{
				mlx->collect.qtd_collect++;
			}
			mlx->x++;
		}
		mlx->y++;
	}
}

void	get_cord_of_collectibles(t_data *mlx)
{
	int	x;
	int	y;
	int	i;

	mlx->collect.cord_x = malloc(sizeof(int) * mlx->collect.qtd_collect);
	mlx->collect.cord_y = malloc(sizeof(int) * mlx->collect.qtd_collect);
	y = 0;
	i = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'C')
			{
				mlx->collect.cord_x[i] = x;
				mlx->collect.cord_y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	(void)argc;
	get_map(&mlx, argv);
	get_positions(&mlx);
	get_x_and_y(&mlx);
	get_cord_of_collectibles(&mlx);

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (mlx.x) * 32, mlx.y * 48, "window");
	get_img(&mlx);
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

