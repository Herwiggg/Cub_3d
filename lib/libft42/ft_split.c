/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:58:50 by almichel          #+#    #+#             */
/*   Updated: 2024/04/05 14:43:40 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i]) && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_strcpy(char **tab, const char *s, char c)
{
	int	j;
	int	k;
	int	i;

	j = 0;
	k = 0;
	i = 0;
	while (k < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			tab[k][j++] = s[i++];
		tab[k][j] = '\0';
		j = 0;
		k++;
	}
	return (tab);
}

char	**ft_doublefree(char **tab, int k)
{
	int	i;

	i = -1;
	while (++i < k)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		k;
	int		i;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	tab = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (k < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i++])
			j++;
		tab[k++] = malloc((j + 1) * sizeof(char));
		if (!tab[k - 1])
			return (ft_doublefree(tab, k));
		j = 0;
	}
	tab[k] = NULL;
	ft_strcpy(tab, s, c);
	return (tab);
}
