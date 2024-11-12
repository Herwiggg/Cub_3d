/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:58:33 by almichel          #+#    #+#             */
/*   Updated: 2023/11/09 16:15:48 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strllen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strllen(s1) + ft_strllen(s2);
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	return (tab);
}
/*
#include <stdio.h>

int main()
{
	char str[] = "test";
	char str2[] = "oui";
	printf("%s\n", ft_strjoin(str, str2));
}*/
