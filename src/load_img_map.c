
#include "../includes/so_long.h"

void	get_img_collect(t_data *mlx)
{
	mlx->collect.collect[0] = load_xpm(*mlx, "./Wizard stay/magic1.xpm");
	mlx->collect.collect[1] = load_xpm(*mlx, "./Wizard stay/magic2.xpm");
	mlx->collect.collect[2] = load_xpm(*mlx, "./Wizard stay/magic3.xpm");
	mlx->collect.collect[3] = load_xpm(*mlx, "./Wizard stay/magic4.xpm");
	mlx->collect.collect[4] = load_xpm(*mlx, "./Wizard stay/magic5.xpm");
	mlx->collect.collect[5] = load_xpm(*mlx, "./Wizard stay/magic6.xpm");
}

void	get_img_map(t_data *mlx)
{
	mlx->maps.door[0] = load_xpm(*mlx, "./Wizard stay/door-close.xpm");
	mlx->maps.door[1] = load_xpm(*mlx, "./Wizard stay/door-open.xpm");
	mlx->maps.wall = load_xpm(*mlx, "./Wizard stay/wall.xpm");
	mlx->maps.floor = load_xpm(*mlx, "./Wizard stay/floor.xpm");
	get_img_map_player_in_door_front(mlx);
	get_img_map_player_in_door_left(mlx);
	get_img_map_player_in_door_right(mlx);
	get_img_map_player_in_door_back(mlx);
}