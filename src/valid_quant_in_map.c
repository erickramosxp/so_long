
#include "../includes/so_long.h"

// Quantidade de Saidas
int	valid_qtd_door_of_map(char **map)
{
	int	y;
	int	x;
	int	qtd_door;

	qtd_door = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				qtd_door++;
			x++;
		}
		y++;
	}
	if (!check_if_print(qtd_door, 1, 1))
		return (0);
	return (1);
}

int	valid_qtd_collect_of_map(char **map)
{
	int	y;
	int	x;
	int	collect;

	collect = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collect++;
			x++;
		}
		y++;
	}
	if (!check_if_print(1, 1, collect))
		return (0);
	return (1);
}

int	valid_qtd_player_of_map(char **map)
{
	int	y;
	int	x;
	int	player;

	player = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	if (!check_if_print(1, player, 1))
		return (0);
	return (1);
}