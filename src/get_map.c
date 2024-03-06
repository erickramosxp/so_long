
#include "../includes/so_long.h"

void	error_map(t_data *mlx)
{
	free_matriz(mlx->map);
	perror("Error: ");
	exit (1);
}

int	get_qtd_line(char **argv)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		perror("Error: ");
		exit (1);
	}
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	get_map(t_data *mlx, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	i = get_qtd_line(argv);
	mlx->map = (char **)malloc(sizeof(char *) * i);
	if (mlx->map == NULL)
		exit (1);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		error_map(mlx);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		mlx->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	mlx->map[i] = '\0';
}
