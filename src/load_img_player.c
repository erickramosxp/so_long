
#include "../includes/so_long.h"

void	get_img_player_front(t_data *mlx)
{
	mlx->player.player[0][0] = load_xpm(*mlx,
			"./Wizard stay/player_front-1.xpm");
	mlx->player.player[0][1] = load_xpm(*mlx,
			"./Wizard stay/player_front-2.xpm");
	mlx->player.player[0][2] = load_xpm(*mlx,
			"./Wizard stay/player_front-3.xpm");
	mlx->player.player[0][3] = load_xpm(*mlx,
			"./Wizard stay/player_front-4.xpm");
}

void	get_img_player_left(t_data *mlx)
{
	mlx->player.player[1][0] = load_xpm(*mlx,
			"./Wizard stay/player_left-1.xpm");
	mlx->player.player[1][1] = load_xpm(*mlx,
			"./Wizard stay/player_left-2.xpm");
	mlx->player.player[1][2] = load_xpm(*mlx,
			"./Wizard stay/player_left-3.xpm");
	mlx->player.player[1][3] = load_xpm(*mlx,
			"./Wizard stay/player_left-4.xpm");
}

void	get_img_player_right(t_data *mlx)
{
	mlx->player.player[2][0] = load_xpm(*mlx,
			"./Wizard stay/player_right-1.xpm");
	mlx->player.player[2][1] = load_xpm(*mlx,
			"./Wizard stay/player_right-2.xpm");
	mlx->player.player[2][2] = load_xpm(*mlx,
			"./Wizard stay/player_right-3.xpm");
	mlx->player.player[2][3] = load_xpm(*mlx,
			"./Wizard stay/player_right-4.xpm");
}

void	get_img_player_back(t_data *mlx)
{
	mlx->player.player[3][0] = load_xpm(*mlx,
			"./Wizard stay/player_back-1.xpm");
	mlx->player.player[3][1] = load_xpm(*mlx,
			"./Wizard stay/player_back-2.xpm");
	mlx->player.player[3][2] = load_xpm(*mlx,
			"./Wizard stay/player_back-3.xpm");
	mlx->player.player[3][3] = load_xpm(*mlx,
			"./Wizard stay/player_back-4.xpm");
}

void	get_img_player(t_data *mlx)
{
	get_img_player_front(mlx);
	get_img_player_left(mlx);
	get_img_player_right(mlx);
	get_img_player_back(mlx);
}