/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:18:29 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:31:29 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_path(char **map, int x, int y, t_data mlx)
{
	if (y < 0 || x < 0 || x > mlx.x || y > mlx.y)
		return ;
	if (map[y][x] == 'P' || map[y][x] == '\0'
		|| map[y][x] == '1' || map[y][x] == 'E' 
			|| map[y][x] == 'C' || map[y][x] == 'B')
		return ;
	map[y][x] = 'P';
	fill_path(map, x + 1, y, mlx);
	fill_path(map, x - 1, y, mlx);
	fill_path(map, x, y + 1, mlx);
	fill_path(map, x, y - 1, mlx);
}

int	check_possible_exit(char **map, t_data mlx)
{
	if (map[mlx.maps.y_door + 1][mlx.maps.x_door] == 'P')
		return (1);
	else if (map[mlx.maps.y_door - 1][mlx.maps.x_door] == 'P')
		return (1);
	else if (map[mlx.maps.y_door][mlx.maps.x_door + 1] == 'P')
		return (1);
	else if (map[mlx.maps.y_door][mlx.maps.x_door - 1] == 'P')
		return (1);
	return (0);
}

int	validate_path(char **map, t_data mlx)
{
	int	x;
	int	y;

	x = mlx.player.player_x;
	y = mlx.player.player_y;
	fill_path(map, x + 1, y, mlx);
	fill_path(map, x - 1, y, mlx);
	fill_path(map, x, y + 1, mlx);
	fill_path(map, x, y - 1, mlx);
	if (!check_possible_exit(map, mlx))
	{
		printf("Error.\n");
		printf("O game que não tem fim.\n");
		return (0);
	}
	return (1);
}
