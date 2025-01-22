/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:41:43 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 23:18:08 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void stock_data(t_data *data)
{
    while (data->file[data->i])
    {
        data->j = 0;
        data->found = 0;
        while (data->file[data->i][data->j] && data->found == 0)
        {
            if (data->file[data->i][data->j] == 'N' && data->file[data->i][data->j + 1] == 'O')
                check_textures(data, &data->count_no, data->_no);
            else if (data->file[data->i][data->j] == 'S' && data->file[data->i][data->j + 1] == 'O')
                check_textures(data, &data->count_so , data->_so);
            else if (data->file[data->i][data->j] == 'W' && data->file[data->i][data->j + 1] == 'E')
                check_textures(data, &data->count_we, data->_we);
            else if (data->file[data->i][data->j] == 'E' && data->file[data->i][data->j + 1] == 'A')
                check_textures(data, &data->count_ea, data->_ea);
            else if (is_a_char_map(data->file[data->i][data->j]) == 0)
                return (copy_map(data->file, data->i, data->j, &(data->map), data));
            else
                stock_data2(data);
            data->j++;
        }
        data->i++;
    }
   complete_checkup(data);
}

void stock_data2(t_data *data)
{
    if(data->file[data->i][data->j] == 'F')
        check_colors_f(data, data->i, data->j);
    else if (data->file[data->i][data->j] == 'C')
        check_colors_c(data, data->i, data->j);
}


void check_textures(t_data *data, int *count, char *text)
{
    (void)text;
    *count += 1;
    data->count_texts++;
    data->found++;
}

void check_colors_f(t_data *data, int i, int j)
{
    if (data->stock_f != NULL)
        ft_errormap2("Wrong colors format\n", data);
    stock_colors(data->file, &(data->_f), i, j);
    check_color(data->_f, data);
    data->stock_f = ft_split_modif(data->_f);
    check_255_color(data->stock_f, data);
    data->count_colors++;
    data->found++;
}

void check_colors_c(t_data *data, int i, int j)
{
    if (data->stock_c != NULL)
        ft_errormap2("Wrong colors format\n", data);
    stock_colors(data->file, &(data->_c), i, j);
    check_color(data->_c, data);
    data->stock_c = ft_split_modif(data->_c);
    check_255_color(data->stock_c, data);
    data->count_colors++;
    data->found++;
}
