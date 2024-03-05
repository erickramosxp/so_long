/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:22:27 by erramos           #+#    #+#             */
/*   Updated: 2023/11/05 15:55:27 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*sub;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char));
		if (!sub)
			return (0);
		sub[0] = '\0';
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	j = 0;
	while (s[start] != '\0' && j < len)
	{
		sub[j] = s[start];
		start++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
