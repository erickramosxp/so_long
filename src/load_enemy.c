/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:23:40 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:33:40 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_img_enemy(t_data *mlx)
{
	mlx->blackhole.enemy[0] = load_xpm(*mlx,
			"./Wizard stay/blackhole0.xpm");
	mlx->blackhole.enemy[1] = load_xpm(*mlx,
			"./Wizard stay/blackhole1.xpm");
	mlx->blackhole.enemy[2] = load_xpm(*mlx,
			"./Wizard stay/blackhole2.xpm");
	mlx->blackhole.enemy[3] = load_xpm(*mlx,
			"./Wizard stay/blackhole3.xpm");
	mlx->blackhole.enemy[4] = load_xpm(*mlx,
			"./Wizard stay/blackhole4.xpm");
	mlx->blackhole.enemy[5] = load_xpm(*mlx,
			"./Wizard stay/blackhole5.xpm");
	mlx->blackhole.enemy[6] = load_xpm(*mlx,
			"./Wizard stay/blackhole6.xpm");
	mlx->blackhole.enemy[7] = load_xpm(*mlx,
			"./Wizard stay/blackhole7.xpm");
	mlx->blackhole.enemy[8] = load_xpm(*mlx,
			"./Wizard stay/blackhole8.xpm");
	mlx->blackhole.enemy[9] = load_xpm(*mlx,
			"./Wizard stay/blackhole9.xpm");
	mlx->blackhole.enemy[10] = load_xpm(*mlx,
			"./Wizard stay/blackhole10.xpm");
	mlx->blackhole.enemy[11] = load_xpm(*mlx,
			"./Wizard stay/blackhole11.xpm");
}
