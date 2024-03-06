
#include "../includes/so_long.h"

void	validate_file(int argc, char **argv)
{
	char	*file;
	int		i;

	if (argc != 2)
		exit(1);
	file = argv[1];
	i = 0;
	while (file[i])
		i++;
	if (i > 4)
		file = file + (i - 4);
	else
		exit(1);
	if (ft_strncmp(file, ".ber", 4))
	{
		printf("Arquivo invalido.\n\n");
		exit(1);
	}
}
