/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:54:00 by erramos           #+#    #+#             */
/*   Updated: 2023/11/05 15:47:30 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const	void *s2, size_t n)
{
	size_t			i;
	unsigned char	*arg1;
	unsigned char	*arg2;

	arg1 = (unsigned char *)s1;
	arg2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (arg1[i] > arg2[i])
			return (1);
		else if (arg1[i] < arg2[i])
			return (-1);
		i++;
	}
	return (0);
}
