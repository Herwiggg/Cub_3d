/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:05:49 by elizohin          #+#    #+#             */
/*   Updated: 2025/01/17 22:34:30 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_tab_tab(char ***tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < 6)
		{
			free_tab(tab[i]);
			i++;
		}
		if (tab)
			free(tab);
	}
}

int	empty_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			j = 1;
			break ;
		}
		i++;
	}
	if (j == 1)
		return (0);
	return (1);
}

void	free_exit(t_jeu *jeu)
{
	free_tab(jeu->value);
	free_tab(jeu->map);
	free_tab(jeu->map_spaced);
	free_tab(jeu->ceiling_colors);
	free_tab(jeu->floor_colors);
	free_tab_tab(jeu->directions);
	free_tab(jeu->file_map);
}

int	ft_errormap(char *str)
{
	int	k;

	k = ft_strlen(str);
	(void)write(1, "Error\n", 6);
	(void)write(1, str, k);
	exit (1);
	return (1);
}
