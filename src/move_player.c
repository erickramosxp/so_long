/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:19:04 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:31:45 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	(*mlx)->moves +=1;
	printf("%d\n", (*mlx)->moves);
}

void	action_key_press(int key, t_data *mlx)
{
	if ((key == XK_Up || key == XK_w) && mlx->map
		[mlx->player.player_y - 1][mlx->player.player_x] != '1')
	{
		condition_move_player(&mlx, 0, -1);
		move_player(&mlx, 0, -1, 3);
	}
	else if ((key == XK_Down || key == XK_s) && mlx->map
		[mlx->player.player_y + 1][mlx->player.player_x] != '1')
	{
		condition_move_player(&mlx, 0, +1);
		move_player(&mlx, 0, +1, 0);
	}
	else if ((key == XK_Left || key == XK_a) && mlx->map
		[mlx->player.player_y][mlx->player.player_x - 1] != '1')
	{
		condition_move_player(&mlx, -1, 0);
		move_player(&mlx, -1, 0, 1);
	}
	else if ((key == XK_Right || key == XK_d)
		&& mlx->map[mlx->player.player_y][mlx->player.player_x + 1] != '1')
	{
		condition_move_player(&mlx, +1, 0);
		move_player(&mlx, +1, 0, 2);
	}
}
