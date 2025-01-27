/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:27:31 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 01:52:59 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_delim(char c)
{
	return (c == ' ' || c == '\t' || c == ',' || c == '\n');
}

int	ft_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_delim(str[i]))
			i++;
		if (str[i] && !is_delim(str[i]))
		{
			count++;
			while (str[i] && !is_delim(str[i]))
				i++;
		}
	}
	return (count);
}

char	**ft_split_modif2(char *str, char **tab)
{
	int	i;
	int	k;
	int	j;
	int	nb_mots;

	nb_mots = ft_count(str);
	i = 0;
	k = 0;
	while (k < nb_mots)
	{
		j = 0;
		while (str[i] && is_delim(str[i]))
			i++;
		while (str[i + j] && !is_delim(str[i + j]))
			j++;
		tab[k] = (char *)malloc(sizeof(char) * (j + 1));
		if (!tab[k])
			return (ft_doublefree(tab, k));
		i += j;
		k++;
	}
	return (tab);
}

char	**ft_strcpy_modif(char **tab, char *str)
{
	int	i;
	int	k;
	int	j;
	int	nb_mots;

	nb_mots = ft_count(str);
	i = 0;
	k = 0;
	while (k < nb_mots)
	{
		j = 0;
		while (str[i] && is_delim(str[i]))
			i++;
		while (str[i] && !is_delim(str[i]))
		{
			tab[k][j] = str[i];
			j++;
			i++;
		}
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split_modif(char *str)
{
	char	**tab;
	int		nb_mots;

	if (!str)
		return (NULL);
	nb_mots = ft_count(str);
	tab = (char **)malloc(sizeof(char *) * (nb_mots + 1));
	if (!tab)
		return (NULL);
	if (!ft_split_modif2(str, tab))
		return (NULL);
	ft_strcpy_modif(tab, str);
	return (tab);
}
