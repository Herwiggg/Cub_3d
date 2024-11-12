/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seya <seya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:13:38 by loculy            #+#    #+#             */
/*   Updated: 2023/06/24 01:21:17 by seya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlenloc(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*m;
	int		i;
	int		sizes1;

	i = 0;
	sizes1 = ft_strlenloc(s1);
	m = (char *)malloc((sizes1 + 1) * sizeof(char));
	if (!m)
		return (0);
	while (i < sizes1)
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}
