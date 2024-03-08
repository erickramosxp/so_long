/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:03:27 by erramos           #+#    #+#             */
/*   Updated: 2023/11/14 14:52:06 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_point(unsigned long long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_printhexp(unsigned long long nb)
{
	int	len;

	len = count_point(nb);
	if (nb >= 16)
	{
		ft_printhexp(nb / 16);
		ft_printhexp(nb % 16);
	}
	else if (nb >= 10)
	{
		ft_putchar(nb + 87);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}

int	ft_printpoint(unsigned long long nb)
{
	int	len;

	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 2;
	write(1, "0x", 2);
	len += ft_printhexp(nb);
	return (len);
}
