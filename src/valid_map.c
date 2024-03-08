/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:16:22 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:16:32 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	caracter_of_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C'
				&& map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'B')
			{
				printf("Error.\n");
				printf("Caracter não reconhecido no mapa.\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_line_map(char **map)
{
	int	y;
	int	line;
	int	prior_line;

	y = 0;
	while (map[y + 1])
	{
		prior_line = ft_strlen(map[y]);
		line = ft_strlen(map[y + 1]);
		if (prior_line > line || prior_line < line)
		{
			printf("Error.\n");
			printf("Mapa desalinhado.\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_all_collectibles(char **map, t_data mlx)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < mlx.collect.qtd_collect)
	{
		x = mlx.collect.cord_x[i];
		y = mlx.collect.cord_y[i];
		if (map[y + 1][x] != 'P' && map[y - 1][x]
			!= 'P' && map[y][x + 1] != 'P' && map[y][x - 1] != 'P')
		{
			printf("Error.\n");
			printf("Coletavel inalcançável.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_map_is_close(char **map, t_data mlx)
{
	int	i;

	i = 0;
	while (i < mlx.y)
	{
		if (map[i][0] != '1' || map[i][mlx.x - 1] != '1')
		{
			printf("Error.\n");
			printf("Mapa inválido.\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < mlx.x)
	{
		if (map[0][i] != '1' || map[mlx.y - 1][i] != '1')
		{
			printf("Error.\n");
			printf("Mapa inválido.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_map(char **map, t_data mlx)
{
	char	**copy;

	copy = copy_matriz(map);
	if (!caracter_of_map(copy) || !valid_qtd_door_of_map(copy)
		|| !valid_qtd_player_of_map(copy) || !valid_qtd_collect_of_map(copy)
		|| !valid_line_map(copy) || !valid_map_is_close(copy, mlx)
		|| !validate_path(copy, mlx) || !check_all_collectibles(copy, mlx))
	{
		free_matriz(copy);
		return (0);
	}
	free_matriz(copy);
	if (mlx.y >= mlx.x)
	{
		printf("Error.\n");
		printf("O mapa não é retangular.\n");
		return (0);
	}
	return (1);
}
