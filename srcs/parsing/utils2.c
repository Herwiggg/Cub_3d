/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:27:31 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 21:22:27 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    ft_count(char *str)
{
    int    count;
    int    i;

    i = 0;
    count = 0;
    while (str[i])
    {
        if ((str[i + 1] == ' ' || str[i + 1]
                || str[i + 1] == '\t' || str[i + 1] == '\n' || str[i + 1] == ',')
            && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&str[i] != ','))
            count++;
        i++;
    }
    return (count);
}

char    **ft_strcpy_modif(char **tab, char *str)
{
    int    k;
    int    i;
    int    j;

    i = 0;
    k = 0;
    j = 0;
    while (k < ft_count(str))
    {
        j = 0;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != ',')
            tab[k][j++] = str[i++];
        tab[k][j] = '\0';
        k++;
        while (str[i] == ' ' || str[i] == '\t' || str[i] == ',')
            i++;
    }
    tab[k] = NULL;
    return (tab);
}

char    **ft_split_modif(char *str)
{
    char    **tab;
    int        k;
    int        i;
    int        j;

    i = 0;
    k = 0;
    j = 0;
    tab = malloc((ft_count(str) + 1) * sizeof(char *));
    if (!tab)
        return (NULL);
    while (k < ft_count(str))
    {
       while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != ',' && str[i] != '\n')
        {
            j++;
            i++;
        }
        tab[k++] = malloc((j + 1) * sizeof(char));
        if (!tab[k - 1])
			return (ft_doublefree(tab, k));
        j = 0;
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',')
            i++;
    }
    ft_strcpy_modif(tab, str);
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

void check_255_color(char **tab)
{
    int i;
    int flag;

    flag = 0;
    i = 0;
    while (tab[i])
    {
        if (ft_atoi(tab[i]) > 255)
        {
            flag = -1;
            break;
        }
        i++;
    }
    if (flag == -1)
        ft_errormap("Wrong color format\n");
   
}
