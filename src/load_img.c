
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
}