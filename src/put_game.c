/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:20:40 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:35:53 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			mlx.win_ptr, mlx.collect.current_collect, x, y);
	else if (obj == 'E')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.maps.current_door, x, y);
	else
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.maps.floor, x, y);
}

void	put_game(t_data mlx)
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
