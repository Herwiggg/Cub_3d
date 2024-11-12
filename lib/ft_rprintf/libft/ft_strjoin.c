/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:24:28 by loculy            #+#    #+#             */
/*   Updated: 2022/11/03 17:11:43 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strjoin_loop(char const *str, char *m, int j)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		m[j] = str[i];
		i++;
		j++;
	}
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*m;
	unsigned int	size;
	unsigned int	j;

	j = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2);
	m = malloc(size * sizeof(char) + 1);
	if (!m)
		return (NULL);
	j = ft_strjoin_loop(s1, m, j);
	ft_strjoin_loop(s2, m, j);
	m[size] = '\0';
	return (m);
}
