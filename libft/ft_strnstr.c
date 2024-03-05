/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:10:42 by erramos           #+#    #+#             */
/*   Updated: 2023/11/08 14:44:45 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_little;

	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	j = 0;
	len_little = ft_strlen(little);
	while (big[i] && i < len)
	{
		while (big[i + j] == little
			[j] && i + j < len && big[i + j] != '\0')
			j++;
		if (j == len_little)
			return ((char *)(big + i));
		j = 0;
		i++;
	}
	return (0);
}
