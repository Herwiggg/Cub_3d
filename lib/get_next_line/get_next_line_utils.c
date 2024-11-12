/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:09:11 by loculy            #+#    #+#             */
/*   Updated: 2023/01/09 15:23:26 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clear_bf(char *buffer, char *a, char *b)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = 0;
	free(a);
	free(b);
	return (0);
}

size_t	ft_strlengnl(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char			*m;
	unsigned int	size;
	unsigned int	j;
	unsigned int	i;

	j = 0;
	if (!s1 && s2)
		return (s2);
	if (!s1 && !s2)
		return (0);
	size = ft_strlengnl(s1) + ft_strlengnl(s2);
	m = malloc(size * sizeof(char) + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (s1[i])
		m[j++] = s1[i++];
	free(s1);
	i = 0;
	while (s2[i])
		m[j++] = s2[i++];
	m[size] = '\0';
	free(s2);
	return (m);
}
