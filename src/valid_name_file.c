/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:22:21 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:32:46 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		printf("Error.\n");
		printf("Arquivo invalido.\n");
		exit(1);
	}
}
