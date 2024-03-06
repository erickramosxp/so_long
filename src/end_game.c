/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:21:50 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:32:16 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
