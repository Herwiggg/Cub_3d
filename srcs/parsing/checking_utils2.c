/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:41:43 by almichel          #+#    #+#             */
/*   Updated: 2025/01/17 22:43:07 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void stock_data(t_data *data)
{
    int i;
    int count_texts;
    int count_colors;
    int j;
    int found;

    found = 1;
    j = 0;
    count_texts = 0;
    count_colors = 0;
    i = 0;
    while (data->file[i])
    {
        j = 0;
        found = 0;
        while (data->file[i][j] && found == 0)
        {
            if (data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
            {
                if (data->_no != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_no), i, j);
                count_texts++;
                found++;
            }
            else if (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
            {
                if (data->_so != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_so), i, j);
                count_texts++;
                found++;
            }
            else if (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
            {
                if (data->_we != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_we), i, j);
                count_texts++;
                found++;
            }
            else if (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A')
            {
                if (data->_ea != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_ea), i, j);
                count_texts++;
                found++;
            }
            else if (data->file[i][j] == 'D' && data->file[i][j + 1] == 'O')
            {
                if (data->_do != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_do), i, j);
                count_texts++;
                found++;
            }
            else if(data->file[i][j] == 'F')
            {
                if (data->stock_f != NULL)
                    ft_errormap("Wrong colors format\n");
                stock_colors(data->file, &(data->_f), i, j);
                check_color(data->_f);
                data->stock_f = ft_split_modif(data->_f);
                free(data->_f);
                check_255_color(data->stock_f);
                count_colors++;
                found++;
            }
            else if (data->file[i][j] == 'C')
            {
                if (data->stock_c != NULL)
                    ft_errormap("Wrong colors format\n");
                stock_colors(data->file, &(data->_c), i, j);
                check_color(data->_c);
                data->stock_c = ft_split_modif(data->_c);
                free(data->_c);
                check_255_color(data->stock_c);
                count_colors++;
                found++;
            }
            else if (is_a_char_map(data->file[i][j]) == 0)
            {
                {
                    copy_map(data->file, i, j, &(data->map));
                    return;
                }
            }
            j++;
        }
        i++;
    }
	if (all_data_are_stocked(data) == -1)
                    ft_errormap("Wrong file format\n");
    if (count_texts != 5)
    {
        ft_errormap("Wrong textures format\n");
        return;
    }
     if (count_colors != 2)
    {
        ft_errormap("Wrong colors format\n");
        return;
    }
}
