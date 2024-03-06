/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:17:29 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:31:05 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animation_player(t_data **mlx)
{
	static int	i;
	static int	frames;

	if (frames == 15)
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

	if (frames == 15)
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
