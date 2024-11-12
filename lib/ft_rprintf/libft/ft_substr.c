/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:37:47 by loculy            #+#    #+#             */
/*   Updated: 2022/11/04 14:03:28 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ft_substr_size(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			j++;
		i++;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*m;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	m = malloc(get_ft_substr_size(s, start, len) * sizeof(char) + 1);
	if (!m)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			m[j] = s[i];
			j++;
		}
		i++;
	}
	m[j] = '\0';
	return (m);
}
