/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:03:16 by erramos           #+#    #+#             */
/*   Updated: 2023/11/05 16:34:10 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_len(char const *s, char c)
{
	int	letter;

	letter = 0;
	while (s[letter] != '\0')
	{
		if (s[letter] != c && (s[letter + 1] == c || s[letter + 1] == '\0'))
			return (letter + 1);
		letter++;
	}
	return (letter);
}

static	char	free_split(char **s, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(s[j]);
		j++;
	}
	free(s);
	return (0);
}

static	char	**allocate_space(const char *s, char c, char **new, int sep)
{
	int	aux;
	int	i;

	i = 0;
	aux = 0;
	while (i < sep)
	{
		while (*s == c && *s != '\0')
			s++;
		aux = word_len(s, c);
		new[i] = ft_substr(s, 0, aux);
		if (!new[i])
		{
			free_split(new, i);
			return (0);
		}
		s = s + aux;
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*aux;
	int		i;
	int		sep;

	sep = 0;
	i = 0;
	if (s == 0)
		return (0);
	aux = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			sep++;
		i++;
	}
	new = malloc((sep + 1) * sizeof(char *));
	if (!new)
		return (0);
	allocate_space(aux, c, new, sep);
	return (new);
}
