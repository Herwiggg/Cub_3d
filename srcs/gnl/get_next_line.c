/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:53:38 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 23:53:38 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft__strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = ft__strlen(s1) + ft__strlen(s2) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	while (i < ft__strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft__strlen(s2))
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (free(s1), str);
}

int	ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == (unsigned char)c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*new_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	while (j <= i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*clean_stock(char *str, size_t i, size_t k)
{
	size_t	j;
	char	*clean;

	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	clean = malloc(sizeof(char) * (ft__strlen(str) - i));
	if (!clean)
		return (free(str), NULL);
	j = i + 1;
	while (str[j])
	{
		clean[k] = str[j];
		j++;
		k++;
	}
	clean[k] = '\0';
	return (free(str), clean);
}

char	*get_next_line(int fd, bool tofree)
{
	static char	*stock;
	char		*buffer;
	char		*line;
	int			char_read;

	if (tofree)
		return (free(stock), NULL);
	char_read = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	check_malloc(buffer);
	while (char_read > 0 && !ft_strchr(stock, '\n'))
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
			return (free(buffer), NULL);
		buffer[char_read] = '\0';
		stock = ft__strjoin(stock, buffer);
		if (!stock)
			return (free(buffer), NULL);
	}
	line = new_line(stock);
	stock = clean_stock(stock, 0, 0);
	return (free(buffer), line);
}
