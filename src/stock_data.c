/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:16:10 by almichel          #+#    #+#             */
/*   Updated: 2024/11/14 19:57:29 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void stock_texts(t_data *data)
{
    int i;
    int count;
    int j;
    int found;

    found = 1;
    j = 0;
    count = 0;
    i = 0;
    while (data->file[i])
    {
        j = 0;
        found = 0;
        while (data->file[i][j] && found == 0)
        {
            if (data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
            {
                stock_texts2(data->file, &(data->_no), i, j);
                count++;
                found++;
            }
            else if (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
            {
                stock_texts2(data->file, &(data->_so), i, j);
                count++;
                found++;
            }
            else if (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
            {
                stock_texts2(data->file, &(data->_we), i, j);
                count++;
                found++;
            }
            else if (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A')
            {
                stock_texts2(data->file, &(data->_ea), i, j);
                count++;
                found++;
            }
            else if (data->file[i][j] == 'D' && data->file[i][j + 1] == 'O')
            {
                stock_texts2(data->file, &(data->_do), i, j);
                count++;
                found++;
            }
            j++;
        }
        i++;
    }
    if (count != 5)
    {
        ft_errormap("Wrong textures format\n");
        return;
    }
}

void stock_texts2(char **file, char **tab, int i, int j)
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

void stock_colors(t_data *data)
{
    int i;
    int count;
    int j;
    int found;
    
    j = 0;
    count = 0;
    i = 0;
    while (data->file[i])
    {
        j = 0;
        found = 0;
        while (data->file[i][j] && found == 0)
        {
            if (data->file[i][j] == 'F')
            {
                stock_texts2(data->file, &(data->_f), i, j);
                check_color(data->_f);
                count++;
                found++;
            }
            else if (data->file[i][j] == 'C')
            {
                stock_texts2(data->file, &(data->_c), i, j);
                check_color(data->_c);
                count++;
                found++;
            }
            j++;
        }
        i++;
    }
    if (count != 2)
    {
        ft_errormap("Wrong colors format\n");
        return;
    }
}

void stock_colors2(char **file, char **tab, int i, int j)
{
    int cpi;
    int cpj;
    int count;
    int index;

    count = 0;
    index = 0;
    cpi = i;
    j = j + 1;
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

void    check_color(char *color)
{
    int i;
    int count;
    
    count = 0;
    i = 0;

    while (color[i])
    {
        if (color[i] == ',')
            count++;
        else if ((color[i] < '0' || color[i] > '9') && (color[i] != ' ' && color[i] != '\t'))
            count = 5;
        i++;
    }
    if (count != 2)
        ft_errormap("wrong color format\n");
    i = 0;
    count = 0;
    while (color[i])
    {
        if (color[i] != ',' && color[i] != ' ' && color[i] != '\t')
        {
            count++;
        }
        else
            count = 0;
        if (count > 3)
            break;
        i++;
    }
     if (count > 3)
        ft_errormap("wrong color format\n");
}
