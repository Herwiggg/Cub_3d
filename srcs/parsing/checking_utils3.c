/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:57:08 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 19:02:40 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    check_color(char *color)
{
    int i;
    int count;
    int flag;

    flag = 0;
    count = 0;
    i = 0;
    check_color2(color, &count);
    while (color[i])
    {
        if (color[i] == ',' && flag == 0)
            ft_errormap("Wrong color format\n");
        if (color[i] == ',')
            flag = 0;
        else if (color[i] >= '0' && color[i] <= '9')
            flag++;
        i++;
    }
     if (count > 3)
        ft_errormap("Wrong color format\n");
    else if (flag == -1 || flag == 0)
        ft_errormap("Wrong color format\n");
}

void check_color2(char *color, int *count)
{
    int i;

    i = 0;
    while (color[i])
    {
        if (color[i] == ',')
            *count += 1;
        else if ((color[i] < '0' || color[i] > '9') && (color[i] != ' ' && color[i] != '\t'))
            *count = 5;
        i++;
    }
    if (*count != 2)
        ft_errormap("Wrong color format\n");
    i = 0;
    *count = 0;
    while (color[i])
    {
        if (color[i] != ',' && color[i] != ' ' && color[i] != '\t')
            *count += 1;
        else
            *count = 0;
        if (*count > 3)
            break;
        i++;
    }
}

void complete_checkup(t_data *data)
{   
    printf("%d\n", data->count_ea);
    if (data->count_ea > 1 || data->count_we > 1|| data->count_no > 1 || data->count_so > 1)
        ft_errormap("Wrong textures format\n");
    if (data->count_texts != 4)
        ft_errormap("Wrong textures format\n");
    if (data->count_colors != 2)
        ft_errormap("Wrong colors format\n");
}
