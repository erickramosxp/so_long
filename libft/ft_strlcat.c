/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:17:15 by erramos           #+#    #+#             */
/*   Updated: 2023/11/05 15:18:18 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t	len_dest;
	size_t	total_size;
	size_t	j;

	j = 0;
	len_dest = ft_strlen(dest);
	if (len_dest >= n)
		return (n + ft_strlen(src));
	while (src[j] != '\0' && len_dest < n - 1)
	{
		dest[len_dest] = src[j];
		len_dest++;
		j++;
	}
	dest[len_dest] = '\0';
	total_size = len_dest + ft_strlen(src) - j;
	return (total_size);
}
