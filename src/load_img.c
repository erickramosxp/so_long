/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:22:48 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:33:01 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*load_xpm(t_data mlx, char *src)
{
	void	*img;
	int		height;
	int		width;

	img = mlx_xpm_file_to_image(mlx.mlx_ptr, src, &height, &width);
	return (img);
}

void	get_img(t_data *mlx)
{
	get_img_collect(mlx);
	get_img_map(mlx);
	get_img_player(mlx);
	get_img_enemy(mlx);
	get_imgs_moves(mlx);
	get_img_nb_moves_right(mlx);
	get_img_nb_moves_left(mlx);
	mlx->direction = 0;
	mlx->player_current = mlx->player.player[0][0];
	mlx->collect.current_collect = mlx->collect.collect[0];
	mlx->maps.current_door = mlx->maps.door[0];
	mlx->blackhole.current_enemy = mlx->blackhole.enemy[0];
	mlx->sprite_moves.hund = mlx->sprite_moves.nb_right[0];
	mlx->sprite_moves.cent = mlx->sprite_moves.nb_left[0];
	mlx->sprite_moves.dez = mlx->sprite_moves.nb_right[0];
	mlx->sprite_moves.uni = mlx->sprite_moves.nb_left[0];
}
