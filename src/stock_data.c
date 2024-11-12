/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:16:10 by almichel          #+#    #+#             */
/*   Updated: 2024/11/12 17:59:36 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void stock_elem(t_data *data)
{
    int i;
    int count;
    int j;

    j = 0;
    count = 0;
    i = 0;
    while (data->file[i])
    {
        j = 0;
        while (data->file[i][j])
        {
            if (data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
            {
                stock_elem2(data->file, &(data->_no), i, j);
                count++;
            }
            else if (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
            {
                stock_elem2(data->file, &(data->_so), i, j);
                count++;
            }
            else if (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
            {
                stock_elem2(data->file, &(data->_we), i, j);
                count++;
            }
            else if (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A')
            {
                stock_elem2(data->file, &(data->_ea), i, j);
                count++;
            }
            else if (data->file[i][j] == 'D' && data->file[i][j + 1] == 'O')
            {
                stock_elem2(data->file, &(data->_do), i, j);
                count++;
            }
            j++;
        }
        i++;
    }
    if (count != 5)
    {
        ft_errormap("Wrong number of elements\n");
        return;
    }
}

void stock_elem2(char **file, char **tab, int i, int j)
{
    int cpi;
    int cpj;
    int count;
    int index;

    count = 0;
    index = 0;
    cpi = i;
    j = j + 2;
    cpj = j;

    while (file[i][j] && (file[i][j] == ' ' || file[i][j] == '\t'))
        j++;
    while (file[i][j])
    {
        j++;
        count++;
    }

    *tab = malloc((count) * sizeof(char));
    if (!(*tab))
        return;

    while (file[cpi][cpj] && (file[cpi][cpj] == ' ' || file[cpi][cpj] == '\t'))
        cpj++;
    while (file[cpi][cpj] && file[cpi][cpj] != '\n')
    {
        (*tab)[index] = file[cpi][cpj];
        index++;
        cpj++;
    }
    (*tab)[index] = '\0';
}

