/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:31:42 by erramos           #+#    #+#             */
/*   Updated: 2023/11/14 14:50:47 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(const char c, unsigned int nb)
{
	int	len;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = count_hex(nb);
	if (nb >= 16)
	{
		ft_printhex(c, nb / 16);
		ft_printhex(c, nb % 16);
	}
	else if (nb >= 10)
	{
		if (c == 'X')
			ft_putchar(nb + 55);
		else
			ft_putchar(nb + 87);
	}
	else
		ft_putchar(nb + '0');
	return (len);
}
