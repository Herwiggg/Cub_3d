/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:32:42 by loculy            #+#    #+#             */
/*   Updated: 2022/11/14 11:25:38 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sep(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_strtrim_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (ft_check_sep(s1[i], set))
			j++;
		else
			return (j);
		i++;
	}
	return (j);
}

static int	ft_strtrim_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (s1[0] == '\0')
		return (0);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s1);
	while (i > 0)
	{
		if (ft_check_sep(s1[i], set))
			j--;
		else
			return (j);
		i--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*m;
	unsigned int	i;
	int				size;
	unsigned int	start;
	unsigned int	end;

	if (!s1 || !set)
		return (0);
	start = ft_strtrim_start(s1, set);
	end = ft_strtrim_end(s1, set);
	size = end - start;
	if (size < 0)
		size = 0;
	m = malloc(size * sizeof(char) + 1);
	if (!m)
		return (NULL);
	i = 0;
	while (start < end)
	{
		m[i] = s1[start];
		start++;
		i++;
	}
	m[i] = '\0';
	return (m);
}
