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
	void	**player[4][4];
	int		player_x;
	int		player_y;
}	t_player;

typedef struct	s_map
{
	void	*floor;
	void	*wall;
	void	*door[2];
	void	**door_close_player[4][4];
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
	int			direction;
	int			x;
	int			y;
	t_collect	collect;
	t_player	player;
	t_map		maps;
}	t_data;

void	destroy_img_matriz(t_data mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mlx_destroy_image(mlx.mlx_ptr, mlx.maps.door_close_player[i][j]);
			mlx_destroy_image(mlx.mlx_ptr, mlx.player.player[i][j]);
			j++;
		}
		i++;
	}
}

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	destroy_img(t_data mlx)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (i < 2)
			mlx_destroy_image(mlx.mlx_ptr, mlx.maps.door[i]);
		if (i < 6)
			mlx_destroy_image(mlx.mlx_ptr, mlx.collect.collect[i]);
		i++;
	}
	destroy_img_matriz(mlx);
	mlx_destroy_image(mlx.mlx_ptr, mlx.maps.floor);
	mlx_destroy_image(mlx.mlx_ptr, mlx.maps.wall);
}

int	destroy_window(t_data *mlx)
{
	destroy_img(*mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx->collect.cord_x);
	free(mlx->collect.cord_y);
	free_matriz(mlx->map);
	exit(0);
	return (0);
}
void	condition_move_player(t_data **mlx, int x, int y)
{
	if ((*mlx)->map[(*mlx)->player.player_y + y][(*mlx)->player.player_x + x]
		== 'E' && (*mlx)->collect.qtd_collect == 0)
		destroy_window(*mlx);
	if ((*mlx)->map[(*mlx)->player.player_y + y][(*mlx)->player.player_x + x]
		== 'C')
		(*mlx)->collect.qtd_collect--;
	if ((*mlx)->maps.x_door == (*mlx)->player.player_x && (*mlx)->maps.y_door
		== (*mlx)->player.player_y)
		(*mlx)->map[(*mlx)->player.player_y][(*mlx)->player.player_x] = 'E';
	else
		(*mlx)->map[(*mlx)->player.player_y][(*mlx)->player.player_x] = '0';
}

void	move_player(t_data **mlx, int x, int y, int index)
{
	if ((*mlx)->map[(*mlx)->player.player_y + y][(*mlx)->player.player_x + x]
		== 'E' && (*mlx)->collect.qtd_collect != 0)
		(*mlx)->player_current = (*mlx)->maps.door_close_player[index][0];
	else
		(*mlx)->player_current = (*mlx)->player.player[index][0];
	(*mlx)->map[(*mlx)->player.player_y + y][(*mlx)->player.player_x + x] = 'P';
	if (y == 0)
		(*mlx)->player.player_x = (*mlx)->player.player_x + x;
	else
		(*mlx)->player.player_y = (*mlx)->player.player_y + y;
	(*mlx)->direction = index;
}

void	action_key_press(int key, t_data *mlx)
{
	if (key == XK_Up && mlx->map
		[mlx->player.player_y - 1][mlx->player.player_x] != '1')
	{
		condition_move_player(&mlx, 0, -1);
		move_player(&mlx, 0, -1, 3);
	}
	else if (key == XK_Down && mlx->map
		[mlx->player.player_y + 1][mlx->player.player_x] != '1')
	{
		condition_move_player(&mlx, 0, +1);
		move_player(&mlx, 0, +1, 0);
	}
	else if (key == XK_Left && mlx->map
		[mlx->player.player_y][mlx->player.player_x - 1] != '1')
	{
		condition_move_player(&mlx, -1, 0);
		move_player(&mlx, -1, 0, 1);
	}
	else if (key == XK_Right &&
		mlx->map[mlx->player.player_y][mlx->player.player_x + 1] != '1')
	{
		condition_move_player(&mlx, +1, 0);
		move_player(&mlx, +1, 0, 2);
	}
}

int	on_keypress(int key, t_data *mlx)
{
	if (key == XK_Escape)
		destroy_window(mlx);
	else
		action_key_press(key, mlx);
	return (0);
}

void	put_img(t_data mlx, char obj, int x, int y)
{
	if (obj == '1')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.maps.wall, x, y);
	else if (obj == 'P')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.player_current, x, y);
	else if (obj == 'C')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.collect.current_collect,  x, y);
	else if (obj == 'E')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.maps.current_door,  x, y);
	else
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.maps.floor, x, y);
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
				put_img(mlx, '1', x * 32, y * 48);
			else if (mlx.map[y][x] == 'P')
				put_img(mlx, 'P', x * 32, y * 48);
			else if (mlx.map[y][x] == 'C')
				put_img(mlx, 'C', x * 32, y * 48);
			else if (mlx.map[y][x] == 'E')
				put_img(mlx, 'E', x * 32, y * 48);
			else
				put_img(mlx, '0', x * 32, y * 48);
			x++;
		}
		y++;
	}
}

void	animation_player(t_data **mlx)
{
	static int	i;
	static int	frames;

	if (frames == 50)
	{
		if ((*mlx)->maps.x_door == (*mlx)->player.player_x
			&& (*mlx)->maps.y_door == (*mlx)->player.player_y)
			(*mlx)->player_current = (*mlx)->maps.door_close_player
			[(*mlx)->direction][i];
		else
			(*mlx)->player_current = (*mlx)->player.player
			[(*mlx)->direction][i];
		i++;
		if (i == 4)
			i = 0;
		frames = 0;
	}
	frames++;
}

void	animation_collect(t_data **mlx)
{
	static int	i;
	static int	j;
	static int	frames;

	if (frames == 50)
	{
		if (j == 0)
		{
			(*mlx)->collect.current_collect = (*mlx)->collect.collect[i];
			i++;
			if (i == 6)
				j = 5;
		}
		if (i == 6)
		{
			(*mlx)->collect.current_collect = (*mlx)->collect.collect[j];
			j--;
			if (j == 0)
				i = 0;
		}
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
	animation_player(&mlx);
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

void	get_img_map_player_in_door_front(t_data *mlx)
{
	mlx->maps.door_close_player[0][0] = load_xpm(*mlx,
			"./Wizard stay/door-close-front-1.xpm");
	mlx->maps.door_close_player[0][1] = load_xpm(*mlx,
			"./Wizard stay/door-close-front-2.xpm");
	mlx->maps.door_close_player[0][2] = load_xpm(*mlx,
			"./Wizard stay/door-close-front-3.xpm");
	mlx->maps.door_close_player[0][3] = load_xpm(*mlx,
			"./Wizard stay/door-close-front-4.xpm");
}
void	get_img_map_player_in_door_left(t_data *mlx)
{
	mlx->maps.door_close_player[1][0] = load_xpm(*mlx,
			"./Wizard stay/door-close-left-1.xpm");
	mlx->maps.door_close_player[1][1] = load_xpm(*mlx,
			"./Wizard stay/door-close-left-2.xpm");
	mlx->maps.door_close_player[1][2] = load_xpm(*mlx,
			"./Wizard stay/door-close-left-3.xpm");
	mlx->maps.door_close_player[1][3] = load_xpm(*mlx,
			"./Wizard stay/door-close-left-4.xpm");
}
void	get_img_map_player_in_door_right(t_data *mlx)
{
	mlx->maps.door_close_player[2][0] = load_xpm(*mlx,
			"./Wizard stay/door-close-right-1.xpm");
	mlx->maps.door_close_player[2][1] = load_xpm(*mlx,
			"./Wizard stay/door-close-right-2.xpm");
	mlx->maps.door_close_player[2][2] = load_xpm(*mlx,
			"./Wizard stay/door-close-right-3.xpm");
	mlx->maps.door_close_player[2][3] = load_xpm(*mlx,
			"./Wizard stay/door-close-right-4.xpm");
}
void	get_img_map_player_in_door_back(t_data *mlx)
{
	mlx->maps.door_close_player[3][0] = load_xpm(*mlx,
			"./Wizard stay/door-close-back-1.xpm");
	mlx->maps.door_close_player[3][1] = load_xpm(*mlx,
			"./Wizard stay/door-close-back-2.xpm");
	mlx->maps.door_close_player[3][2] = load_xpm(*mlx,
			"./Wizard stay/door-close-back-3.xpm");
	mlx->maps.door_close_player[3][3] = load_xpm(*mlx,
			"./Wizard stay/door-close-back-4.xpm");
}

void	get_img_map(t_data *mlx)
{
	mlx->maps.door[1] = load_xpm(*mlx, "./Wizard stay/door-open.xpm");
	mlx->maps.door[0] = load_xpm(*mlx, "./Wizard stay/door-close.xpm");
	mlx->maps.wall = load_xpm(*mlx, "./Wizard stay/wall.xpm");
	mlx->maps.floor = load_xpm(*mlx, "./Wizard stay/floor.xpm");
	get_img_map_player_in_door_front(mlx);
	get_img_map_player_in_door_left(mlx);
	get_img_map_player_in_door_right(mlx);
	get_img_map_player_in_door_back(mlx);
}

void	get_img_player_front(t_data *mlx)
{
	mlx->player.player[0][0] = load_xpm(*mlx,
			"./Wizard stay/player_front-1.xpm");
	mlx->player.player[0][1] = load_xpm(*mlx,
			"./Wizard stay/player_front-2.xpm");
	mlx->player.player[0][2] = load_xpm(*mlx,
			"./Wizard stay/player_front-3.xpm");
	mlx->player.player[0][3] = load_xpm(*mlx,
			"./Wizard stay/player_front-4.xpm");
}

void	get_img_player_left(t_data *mlx)
{
	mlx->player.player[1][0] = load_xpm(*mlx,
			"./Wizard stay/player_left-1.xpm");
	mlx->player.player[1][1] = load_xpm(*mlx,
			"./Wizard stay/player_left-2.xpm");
	mlx->player.player[1][2] = load_xpm(*mlx,
			"./Wizard stay/player_left-3.xpm");
	mlx->player.player[1][3] = load_xpm(*mlx,
			"./Wizard stay/player_left-4.xpm");
}
void	get_img_player_right(t_data *mlx)
{
	mlx->player.player[2][0] = load_xpm(*mlx,
			"./Wizard stay/player_right-1.xpm");
	mlx->player.player[2][1] = load_xpm(*mlx,
			"./Wizard stay/player_right-2.xpm");
	mlx->player.player[2][2] = load_xpm(*mlx,
			"./Wizard stay/player_right-3.xpm");
	mlx->player.player[2][3] = load_xpm(*mlx,
			"./Wizard stay/player_right-4.xpm");
}
void	get_img_player_back(t_data *mlx)
{
	mlx->player.player[3][0] = load_xpm(*mlx,
			"./Wizard stay/player_back-1.xpm");
	mlx->player.player[3][1] = load_xpm(*mlx,
			"./Wizard stay/player_back-2.xpm");
	mlx->player.player[3][2] = load_xpm(*mlx,
			"./Wizard stay/player_back-3.xpm");
	mlx->player.player[3][3] = load_xpm(*mlx,
			"./Wizard stay/player_back-4.xpm");
}

void	get_img_player(t_data *mlx)
{
	get_img_player_front(mlx);
	get_img_player_left(mlx);
	get_img_player_right(mlx);
	get_img_player_back(mlx);
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

char	**copy_matriz(char **matriz)
{
	char **copy;
	int	i;

	i = 0;
	while(matriz[i] != NULL)
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (0);
	i = 0;
	while (matriz[i])
	{
		copy[i] = ft_strdup(matriz[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	caracter_of_map(char **map)
{
	int	y;
	int	x;
	int qtd_door;

	y = 0;
	qtd_door = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'P' && map[y][x] != 'E')
			{
				// Montar a logica para dar free em tudo se isso ocorrer
				printf("\n\nCaracter diferente no mapa.\n\n");
				return (0);
			}
			if (map[y][x] == 'E')
				qtd_door++;
			x++;
		}
		y++;
	}
	if (qtd_door > 1)
		return (0);
	return (1);
}

// Quantidade de Saidas
int	qtd_door_of_map(char **map)
{
	int	y;
	int	x;
	int qtd_door;
	int collect;
	int player;

	y = 0;
	qtd_door = 0;
	collect = 0;
	player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				qtd_door++;
			if (map[y][x] == 'C')
				collect++;
			if (map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	if (qtd_door > 1 || collect < 1 || player != 1)
		return (0);
	return (1);
}

int	size_map(char **map)
{
	int	y;
	int	line;
	int prior_line;

	y = 0;
	while (map[y + 1])
	{
		prior_line = ft_strlen(map[y]);
		line = ft_strlen(map[y + 1]);
		if (prior_line > line || prior_line < line)
		{
			printf("\n\nUma linha maior que a outra.\n\n");
			return (0);
		}
		y++;
	}
	return (1);
}

void	fill_path(char **map, int x, int y, t_data mlx)
{
	if (y < 0 || x < 0 || x > mlx.x || y > mlx.y)
		return ;
	if (map[y][x] == 'P' || map[y][x] == '\0' || map[y][x] == '1' || map[y][x] == 'E')
		return ;
	map[y][x] = 'P';
	fill_path(map, x + 1, y, mlx);
	fill_path(map, x - 1, y, mlx);
	fill_path(map, x, y + 1, mlx);
	fill_path(map, x, y - 1, mlx);
}

int	validate_path(char **map, t_data mlx)
{
	int i;
	int	x;
	int y;

	i = 0;
	x = mlx.player.player_x;
	y = mlx.player.player_y;
	if (map[y + 1][x] == '0')
		y += 1;
	else if (map[y - 1][x] == '0')
		y -= 1;
	else if (map[y][x + 1] == '0')
		x += 1;
	else if (map[y][x - 1] == '0')
		x -= 1;
	fill_path(map, x, y, mlx);
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (1);
}

void	valid_map(char **map, t_data mlx)
{
	char **copy;

	copy = copy_matriz(map);
	caracter_of_map(copy);
	qtd_door_of_map(copy);
	size_map(copy);
	validate_path(copy, mlx);
	free_matriz(copy);
}

void	validate_file(int argc, char **argv)
{
	char	*file;
	int		i;

	if (argc != 2)
		exit(1);
	(void)argv;
	file = argv[1];
	i = 0;
	while (file[i])
		i++;
	if (i > 4)
		file = file + (i - 4);
	else
		exit(1);
	printf("%s\n", file);
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	validate_file(argc, argv);
	mlx.mlx_ptr = mlx_init();
	get_map(&mlx, argv);
	get_positions(&mlx);
	get_x_and_y(&mlx);
	valid_map(mlx.map, mlx);
	get_cord_of_collectibles(&mlx);
	get_img(&mlx);
	mlx.direction = 0;
	mlx.player_current = mlx.player.player[0][0];
	mlx.collect.current_collect = mlx.collect.collect[0];
	mlx.maps.current_door = mlx.maps.door[0];
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
			(mlx.x) * 32, mlx.y * 48, "window");
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &on_keypress, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &put_init, (void *)&mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &destroy_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
