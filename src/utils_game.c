/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:24:36 by erramos           #+#    #+#             */
/*   Updated: 2024/03/06 17:34:14 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_if_print(int quant_door, int quant_player, int quant_collect)
{
	if (quant_door <= 0)
	{
		printf("Error\n");
		printf("Nenhuma saida.\n");
		return (0);
	}
	else if (quant_player <= 0 || quant_player > 1)
	{
		printf("Error\n");
		printf("Quantidade de player invalida\n.");
		return (0);
	}
	else if (quant_collect <= 0)
	{
		printf("Error\n");
		printf("Nenhum coletavel.\n");
		return (0);
	}
	return (1);
}

char	**copy_matriz(char **matriz)
{
	char	**copy;
	int		i;

	i = 0;
	while (matriz[i] != NULL)
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (0);
	i = 0;
	while (matriz[i])
	{
		copy[i] = ft_strdup(matriz[i]);
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	if_door(t_data **mlx)
{
	if ((*mlx)->collect.qtd_collect == 0)
		(*mlx)->maps.current_door = (*mlx)->maps.door[1];
}
