/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:49:03 by erramos           #+#    #+#             */
/*   Updated: 2023/11/05 15:57:59 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char a, const char *b)
{
	int	i;

	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static	void	fill_array(const char *s1, char *new, int i, int j)
{
	int	k;

	k = 0;
	while (i <= j)
	{
		new[k] = s1[i];
		i++;
		k++;
	}
	new[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		j;
	int		i;

	if (s1 == 0 || set == 0)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && check(s1[i], set))
		i++;
	while (j >= 0 && check(s1[j], set))
		j--;
	if (i > j)
		return (ft_strdup(""));
	new = (char *)malloc(((j - i + 1) * sizeof(char)) + 1);
	if (!(new))
		return (0);
	fill_array(s1, new, i, j);
	return (new);
}
