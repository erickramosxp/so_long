/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:21:13 by erramos           #+#    #+#             */
/*   Updated: 2024/03/08 12:15:54 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
//# include <string.h>

typedef struct s_moves
{
	void	*img_moves[4];
	void	*nb_left[10];
	void	*nb_right[10];
	void	*hund;
	void	*cent;
	void	*dez;
	void	*uni;
}	t_moves;

typedef struct s_enemy
{
	void	*enemy[7];
	void	*current_enemy;
	int		qtd_enemy;
	int		*cord_x;
	int		*cord_y;
}	t_enemy;

typedef struct s_collect
{
	void	*collect[6];
	void	*current_collect;
	int		qtd_collect;
	int		*cord_x;
	int		*cord_y;
}	t_collect;

typedef struct s_player
{
	void	**player[4][4];
	int		player_x;
	int		player_y;
}	t_player;

typedef struct s_map
{
	void	*floor;
	void	*wall;
	void	*door[2];
	void	**door_close_player[4][4];
	void	*current_door;
	int		x_door;
	int		y_door;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*player_current;
	char		**map;
	int			direction;
	int			moves;
	int			x;
	int			y;
	t_collect	collect;
	t_player	player;
	t_map		maps;
	t_enemy		blackhole;
	t_moves		sprite_moves;
}	t_data;

void	validate_file(int argc, char **argv);

int		valid_map(char **map, t_data mlx);
int		valid_qtd_door_of_map(char **map);
int		valid_qtd_collect_of_map(char **map);
int		valid_qtd_player_of_map(char **map);
int		caracter_of_map(char **map);
int		valid_qtd_door_of_map(char **map);
int		valid_line_map(char **map);
int		valid_map_is_close(char **map, t_data mlx);

void	fill_path(char **map, int x, int y, t_data mlx);
int		check_possible_exit(char **map, t_data mlx);
int		validate_path(char **map, t_data mlx);
int		check_all_collectibles(char **map, t_data mlx);

char	**copy_matriz(char **matriz);
int		check_if_print(int quant_door, int quant_player, int quant_collect);
void	if_door(t_data **mlx);

int		get_qtd_line(char **argv);
void	get_map(t_data *mlx, char **argv);
void	error_map(t_data *mlx);

void	get_positions(t_data *mlx);
void	get_qtd_collect_and_x_y_of_map(t_data *mlx);
void	get_cord_of_collectibles(t_data *mlx);
void	get_qtd_enemies(t_data *mlx);
void	get_cord_of_enemies(t_data *mlx);

void	*load_xpm(t_data mlx, char *src);
void	get_img(t_data *mlx);
void	get_img_collect(t_data *mlx);
void	get_img_map(t_data *mlx);
void	get_img_player_front(t_data *mlx);
void	get_img_player_left(t_data *mlx);
void	get_img_player_right(t_data *mlx);
void	get_img_player_back(t_data *mlx);
void	get_img_player(t_data *mlx);
void	get_img_enemy(t_data *mlx);
void	get_imgs_moves(t_data *mlx);
void	get_img_nb_moves_right(t_data *mlx);
void	get_img_nb_moves_left(t_data *mlx);

void	get_img_map_player_in_door_front(t_data *mlx);
void	get_img_map_player_in_door_left(t_data *mlx);
void	get_img_map_player_in_door_right(t_data *mlx);
void	get_img_map_player_in_door_back(t_data *mlx);

void	animation_player(t_data **mlx);
void	animation_collect(t_data **mlx);
void	animation_enemy(t_data **mlx);
void	update_img_moves(t_data *mlx);

void	put_img(t_data mlx, char obj, int x, int y);
void	put_game(t_data mlx);

void	condition_move_player(t_data **mlx, int x, int y);
void	move_player(t_data **mlx, int x, int y, int index);
void	action_key_press(int key, t_data *mlx);

void	destroy_img_matriz(t_data mlx);
void	free_matriz(char **matriz);
void	destroy_img(t_data mlx);
int		destroy_window(t_data *mlx);

#endif
