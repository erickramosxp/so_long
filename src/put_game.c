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
	else if (obj == 'B')
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.blackhole.current_enemy, x, y);
	else
		mlx_put_image_to_window(mlx.mlx_ptr,
			mlx.win_ptr, mlx.maps.floor, x, y);
}

void	put_moves(t_data mlx)
{
	mlx_put_image_to_window(mlx.mlx_ptr,
		mlx.win_ptr, mlx.sprite_moves.img_moves[0], 0, 0);
	mlx_put_image_to_window(mlx.mlx_ptr,
		mlx.win_ptr, mlx.sprite_moves.img_moves[1], 32, 0);
	mlx_put_image_to_window(mlx.mlx_ptr,
		mlx.win_ptr, mlx.sprite_moves.img_moves[2], 64, 0);
	mlx_put_image_to_window(mlx.mlx_ptr,
		mlx.win_ptr, mlx.sprite_moves.hund, 80, 0);
	mlx_put_image_to_window(mlx.mlx_ptr,
		mlx.win_ptr, mlx.sprite_moves.cent, 96, 0);
	mlx_put_image_to_window(mlx.mlx_ptr,
		mlx.win_ptr, mlx.sprite_moves.dez, 112, 0);
	mlx_put_image_to_window(mlx.mlx_ptr,
		mlx.win_ptr, mlx.sprite_moves.uni, 128, 0);
	mlx_put_image_to_window(mlx.mlx_ptr,
		mlx.win_ptr, mlx.sprite_moves.img_moves[3], 144, 0);
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
			if (((x * 32) < 160) && ((y * 48) < 48))
				put_moves(mlx);
			else
				put_img(mlx, mlx.map[y][x], x * 32, y * 48);
			x++;
		}
		y++;
	}
}
