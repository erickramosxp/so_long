/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:21:13 by erramos           #+#    #+#             */
/*   Updated: 2024/03/05 20:21:15 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./get_next_line/get_next_line.h"
# include "./includes/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_collect
{
	void	*collect[6];
	void	*current_collect;
	int		qtd_collect;
	int		*cord_x;
	int		*cord_y;
}	t_collect;

typedef	struct	s_player
{
	void	**player[4][4];
	int		player_x;
	int		player_y;
}	t_player;

typedef struct	s_map
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
	int			x;
	int			y;
	t_collect	collect;
	t_player	player;
	t_map		maps;
}	t_data;


#endif
