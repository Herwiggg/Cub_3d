/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:19:14 by almichel          #+#    #+#             */
/*   Updated: 2024/11/24 23:39:03 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void copy_map(char **file, int i, int j, char ***map)
{
    int count;
    int cp_i;
    int flag;
    int k;
    int flag_empty;

    flag_empty = 0;
    k = 0;
    flag = 0;
    j = 0;
    cp_i = i;
    count = 0;

    // Count the lines in the file starting from index `i`
    while (file[i])
    {
        j = 0;
        flag_empty = 0;
        while (file[i][j])
        {
            if (j == 0 && file[i][j] == '\n')
            {
                flag = 1;
                break;
            }
            if (file[i][j] != '\n' && file[i][j] != ' ' && file[i][j] != '\t')
                flag_empty = 1;
            j++;
        }
        if (flag_empty == 0)
        {
            ft_errormap("Wrong file format\n");
            break;
        }
        count++;
        i++;
    }
    if (flag == 1)
        ft_errormap("Wrong file format\n");

    // Allocate memory for the map
    *map = malloc((count + 1) * sizeof(char *));
    if (!(*map))
        return;

    i = cp_i;
    j = 0;

    // Allocate memory for each line in the map
    while (k < count)
    {
        j = 0;
        while (file[i][j])
            j++;
        (*map)[k] = malloc((j + 1) * sizeof(char));
        if (!(*map)[k])
        {
            ft_doublefree(*map, k);
            return;
        }
        i++;
        k++;
    }
    (*map)[k] = NULL; // Null-terminate the map array

    k = 0;
    i = cp_i;
    j = 0;
    while (k < count)
    {
        while (file[i][j])
        {
            (*map)[k][j] = file[i][j];
            j++;
        }
        (*map)[k][j] = '\0';
        j = 0;
        k++;
        i++;
    }
}
