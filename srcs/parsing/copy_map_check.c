/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:30:55 by almichel          #+#    #+#             */
/*   Updated: 2025/01/23 00:36:56 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void copy_map(t_data *data, int i, int j, char ***map)
{
    int count;
    int cp_i;
    int k;

    k = -1;
    cp_i = i;
    count = 0;
    complete_checkup(data);
    copy_map2(data->file, i, &count);
    *map = malloc((count + 1) * sizeof(char *));
    if (!(*map))
        return;
    i = cp_i;
    copy_map3(data->file, i, count, map);
    while (++k < count)
    {
        j = 0;
        while (data->file[i][j])
        {
            (*map)[k][j] = data->file[i][j];
            j++;
        }
        (*map)[k][j] = '\0';
        i++;
    }
}

void copy_map2(char **file, int i, int *count)
{
    int j;
    int flag;
    int flag_empty;

    flag_empty = 0;
    flag = 0;
    while (file[i])
    {
        j = 0;
        flag_empty = 0;
        while (file[i][j])
        {
            if (j == 0 && file[i][j] == '\n')
                ft_errormap("Wrong file format\n");
            if (file[i][j] != '\n' && file[i][j] != ' ' && file[i][j] != '\t')
                flag_empty = 1;
            j++;
        }
        if (flag_empty == 0)
            ft_errormap("Wrong file format\n");
        *count += 1;
        i++;
    }
    if (flag == 1)
        ft_errormap("Wrong file format\n");
}

void copy_map3(char **file, int i, int count, char ***map)
{
    int j;
    int k;

    k = 0;
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
        i += 1;
        k++;
    }
    (*map)[k] = NULL;
}
