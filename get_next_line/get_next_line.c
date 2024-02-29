/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:32:11 by erramos           #+#    #+#             */
/*   Updated: 2024/02/23 15:45:39 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_breakline(char *rest)
{
	int	i;

	i = 0;
	while (rest[i] != '\0')
	{
		if (rest[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *rest, int rd)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buffer);
			return (0);
		}
		if (rd == 0)
			break ;
		buffer[rd] = '\0';
		if (!rest)
			rest = ft_strdup("");
		rest = ft_strjoin_gnl(rest, buffer);
		if (check_breakline(rest))
			break ;
	}
	free(buffer);
	return (rest);
}

char	*get_line(char *line, char *rest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!rest)
		return (NULL);
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	while (j <= i)
	{
		line[j] = rest[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*remove_breakline(char *rest)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (rest[i] == '\0' || (rest[i] == '\n' && rest[i + 1] == '\0'))
	{
		free(rest);
		return (NULL);
	}
	j = i;
	while (rest[j] != '\0')
		j++;
	temp = ft_strdup(rest);
	free(rest);
	rest = (char *)malloc((j - i + 1) * sizeof(char));
	i++;
	copy(rest, temp, i, 0);
	free(temp);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest = read_line(fd, rest, 1);
	if (!rest)
	{
		return (NULL);
	}
	line = get_line(line, rest);
	rest = remove_breakline(rest);
	return (line);
}
