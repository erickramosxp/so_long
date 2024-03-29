/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:20:15 by erramos           #+#    #+#             */
/*   Updated: 2024/03/08 10:54:52 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	get_qtd_collect_and_x_y_of_map(t_data *mlx)
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

void	get_qtd_enemies(t_data *mlx)
{
	int	y;
	int	x;

	y = 0;
	mlx->blackhole.qtd_enemy = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'B')
			{
				mlx->blackhole.qtd_enemy++;
			}
			x++;
		}
		y++;
	}
}

void	get_cord_of_enemies(t_data *mlx)
{
	int	x;
	int	y;
	int	i;

	mlx->blackhole.cord_x = malloc(sizeof(int) * mlx->blackhole.qtd_enemy);
	mlx->blackhole.cord_y = malloc(sizeof(int) * mlx->blackhole.qtd_enemy);
	y = 0;
	i = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'B')
			{
				mlx->blackhole.cord_x[i] = x;
				mlx->blackhole.cord_y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
}
