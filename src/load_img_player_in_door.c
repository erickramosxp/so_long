/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_player_in_door.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:16:48 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:30:44 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
