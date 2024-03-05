/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:47:17 by erramos           #+#    #+#             */
/*   Updated: 2023/11/05 16:20:36 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_digits(int value, int *signal)
{
	int	digit;

	digit = 0;
	if (value < 0)
	{
		value = -value;
		digit++;
		*signal = 1;
	}
	else
		*signal = 0;
	while (value != 0)
	{
		digit++;
		value = value / 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*new;
	int		signal;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = check_digits(n, &signal);
	new = (char *)malloc((digit + 1) * sizeof(char));
	if (!new)
		return (0);
	new[digit] = '\0';
	digit--;
	if (n < 0)
		n = -n;
	while (0 <= digit)
	{
		new[digit] = (n % 10) + '0';
		n = n / 10;
		digit--;
	}
	if (signal)
		new[0] = '-';
	return (new);
}
