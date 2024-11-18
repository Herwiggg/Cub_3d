/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:03:07 by almichel          #+#    #+#             */
/*   Updated: 2024/11/18 19:30:28 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
    while (str[i])
    {
        j = 0;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != ',')
        tab[k][j++] = str[i++];
    tab[k++][j] = '\0';
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
        while (str[i++] && str[i++] != ' ' && str[i++] != '\t' && str[i++] == ',')
            j++;
    tab[k++] = malloc((j + 1) * sizeof(char));
    j = 0;
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',')
            i++;
    }
    ft_strcpy_modif(tab, str);
    return (tab);
}


