/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizohin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:23:23 by elizohin          #+#    #+#             */
/*   Updated: 2023/05/03 19:23:23 by elizohin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
-  recherche la 1e lettre de la chaine to_find dans la chaîne str
- mais en cherchant que jusqua n premiers caractères de str
- retourne un ptr vers le début de la sous-chaîne
- la fct renvoie un ptr vers le début de la 1e occurence de to_find dans str
*/

#include "libft.h"
#include <string.h>

static unsigned int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	to_find_len;

	if (to_find == NULL || str == NULL)
		if (n == 0)
			return ((char *)str);
	if (*to_find == '\0')
		return ((char *)str);
	if (*str == '\0')
		return (NULL);
	to_find_len = ft_len(to_find);
	while (*str && to_find_len <= n--)
	{
		if (!ft_memcmp(str, to_find, to_find_len))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
