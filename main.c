/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:53:46 by erramos           #+#    #+#             */
/*   Updated: 2024/03/05 19:53:49 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	on_keypress(int key, t_data *mlx)
{
	if (key == XK_Escape)
		destroy_window(mlx);
	else
		action_key_press(key, mlx);
	return (0);
}

void	if_enemy(t_data *mlx)
{
	int	i;
	int	enemy;

	i = 0;
	enemy = mlx->blackhole.qtd_enemy;
	while (i < enemy)
	{
		if (mlx->player.player_x == mlx->blackhole.cord_x[i]
			&& mlx->player.player_y == mlx->blackhole.cord_y[i])
		{
			mlx->map[mlx->player.player_y][mlx->player.player_x] = 'B';
			put_game(*mlx);
			sleep(1);
			destroy_window(mlx);
		}
		i++;
	}
}

int	put_init(t_data *mlx)
{
	if_enemy(mlx);
	if_door(&mlx);
	animation_player(&mlx);
	animation_collect(&mlx);
	animation_enemy(&mlx);
	put_game(*mlx);
	return (1);
}

void	init_game(char **argv, t_data *mlx)
{
	get_map(mlx, argv);
	get_positions(mlx);
	get_qtd_collect_and_x_y_of_map(mlx);
	get_cord_of_collectibles(mlx);
	get_qtd_enemies(mlx);
	get_cord_of_enemies(mlx);
	if (!valid_map(mlx->map, *mlx))
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		free_matriz(mlx->map);
		free(mlx->collect.cord_x);
		free(mlx->collect.cord_y);
		free(mlx->blackhole.cord_x);
		free(mlx->blackhole.cord_y);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	validate_file(argc, argv);
	mlx.mlx_ptr = mlx_init();
	init_game(argv, &mlx);
	get_img(&mlx);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, (mlx.x) * 32, mlx.y * 48,
			"window");
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &on_keypress, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &put_init, (void *)&mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &destroy_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
