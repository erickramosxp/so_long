/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:50:51 by erramos           #+#    #+#             */
/*   Updated: 2024/03/08 10:52:45 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_img_nb_moves_left(t_data *mlx)
{
	mlx->sprite_moves.nb_left[0] = load_xpm(*mlx,
			"./Wizard stay/number/0-left.xpm");
	mlx->sprite_moves.nb_left[1] = load_xpm(*mlx,
			"./Wizard stay/number/1-left.xpm");
	mlx->sprite_moves.nb_left[2] = load_xpm(*mlx,
			"./Wizard stay/number/2-left.xpm");
	mlx->sprite_moves.nb_left[3] = load_xpm(*mlx,
			"./Wizard stay/number/3-left.xpm");
	mlx->sprite_moves.nb_left[4] = load_xpm(*mlx,
			"./Wizard stay/number/4-left.xpm");
	mlx->sprite_moves.nb_left[5] = load_xpm(*mlx,
			"./Wizard stay/number/5-left.xpm");
	mlx->sprite_moves.nb_left[6] = load_xpm(*mlx,
			"./Wizard stay/number/6-left.xpm");
	mlx->sprite_moves.nb_left[7] = load_xpm(*mlx,
			"./Wizard stay/number/7-left.xpm");
	mlx->sprite_moves.nb_left[8] = load_xpm(*mlx,
			"./Wizard stay/number/8-left.xpm");
	mlx->sprite_moves.nb_left[9] = load_xpm(*mlx,
			"./Wizard stay/number/9-left.xpm");
}

void	get_img_nb_moves_right(t_data *mlx)
{
	mlx->sprite_moves.nb_right[0] = load_xpm(*mlx,
			"./Wizard stay/number/0-right.xpm");
	mlx->sprite_moves.nb_right[1] = load_xpm(*mlx,
			"./Wizard stay/number/1-right.xpm");
	mlx->sprite_moves.nb_right[2] = load_xpm(*mlx,
			"./Wizard stay/number/2-right.xpm");
	mlx->sprite_moves.nb_right[3] = load_xpm(*mlx,
			"./Wizard stay/number/3-right.xpm");
	mlx->sprite_moves.nb_right[4] = load_xpm(*mlx,
			"./Wizard stay/number/4-right.xpm");
	mlx->sprite_moves.nb_right[5] = load_xpm(*mlx,
			"./Wizard stay/number/5-right.xpm");
	mlx->sprite_moves.nb_right[6] = load_xpm(*mlx,
			"./Wizard stay/number/6-right.xpm");
	mlx->sprite_moves.nb_right[7] = load_xpm(*mlx,
			"./Wizard stay/number/7-right.xpm");
	mlx->sprite_moves.nb_right[8] = load_xpm(*mlx,
			"./Wizard stay/number/8-right.xpm");
	mlx->sprite_moves.nb_right[9] = load_xpm(*mlx,
			"./Wizard stay/number/9-right.xpm");
}

void	get_imgs_moves(t_data *mlx)
{
	mlx->sprite_moves.img_moves[0] = load_xpm(*mlx, "./Wizard stay/mo.xpm");
	mlx->sprite_moves.img_moves[1] = load_xpm(*mlx, "./Wizard stay/ve.xpm");
	mlx->sprite_moves.img_moves[2] = load_xpm(*mlx, "./Wizard stay/s.xpm");
	mlx->sprite_moves.img_moves[3] = load_xpm(*mlx,
			"./Wizard stay/wall-right.xpm");
}
