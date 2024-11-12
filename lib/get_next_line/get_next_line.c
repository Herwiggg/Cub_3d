/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:03:07 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 19:42:28 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_buffer_mg(char *buffer)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (buffer[j] != '\0' && buffer[j] != '\n')
		j++;
	if (buffer[j] == '\n')
		j++;
	while (buffer[j] != '\0')
		buffer[i++] = buffer[j++];
	buffer[i] = '\0';
}

char	*ft_read(char *buffer)
{
	unsigned int	size;
	unsigned int	i;
	char			*m;

	i = 0;
	size = 0;
	while (buffer[size] != '\0' && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	m = malloc(size + 1 * sizeof(char));
	if (!m)
		return (0);
	while (i < size)
	{
		m[i] = buffer[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

char	*ft_readjoin(char *buffer, char *line)
{
	char	*oldline;
	char	*m;

	m = ft_read(buffer);
	if (!m)
		return (ft_clear_bf(buffer, line, 0));
	oldline = ft_strjoingnl(line, m);
	if (!oldline)
		return (ft_clear_bf(buffer, line, m));
	ft_buffer_mg(buffer);
	return (oldline);
}

char	*ft_read_line(int fd, char *buffer, char *line, ssize_t sz_file)
{
	char			*oldline;

	oldline = ft_readjoin(buffer, line);
	if (!oldline)
		return (0);
	if (ft_strlengnl(oldline) > 0)
		if (oldline[ft_strlengnl(oldline) - 1] == '\n')
			return (oldline);
	sz_file = read(fd, buffer, BUFFER_SIZE);
	buffer[sz_file] = 0;
	if (sz_file == 0 && ft_strlengnl(oldline) < 1)
	{
		free(oldline);
		return (0);
	}
	line = ft_readjoin(buffer, oldline);
	if (!line)
		return (0);
	if (line[ft_strlengnl(line) - 1] == '\n' || sz_file < BUFFER_SIZE)
		return (line);
	else if (sz_file == BUFFER_SIZE)
		return (ft_read_line(fd, buffer, line, sz_file));
	free(line);
	return (0);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (read(fd, 0, 0) < 0)
		return (ft_clear_bf(buffer, 0, 0));
	return (ft_read_line(fd, buffer, 0, 0));
}
