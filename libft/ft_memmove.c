/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:19:17 by erramos           #+#    #+#             */
/*   Updated: 2023/11/05 14:17:55 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	if (!dest2 && !src2)
		return (0);
	if (dest2 > src2)
	{
		dest2 = dest2 + (n - 1);
		src2 = src2 + (n - 1);
		while (n)
		{
			*dest2-- = *src2--;
			n--;
		}
	}
	else
		ft_memcpy(dest2, src2, n);
	return (dest);
}
