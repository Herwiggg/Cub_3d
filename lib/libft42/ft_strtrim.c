/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:27:12 by almichel          #+#    #+#             */
/*   Updated: 2023/11/14 13:28:04 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dest;
	size_t		i;
	size_t		start;
	size_t		end;

	start = 0;
	i = 0;
	if (!s1)
		return (NULL);
	while (s1[start] && is_in(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in(set, s1[end - 1]))
		end--;
	dest = malloc(sizeof(*s1) * (end - start + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (start < end)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}
