/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:21:50 by erramos           #+#    #+#             */
/*   Updated: 2023/11/12 17:46:18 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_u(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_printu(unsigned int nb)
{
	int	len;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = len_u(nb);
	if (nb > 9)
	{
		ft_printu(nb / 10);
		ft_printu(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}
