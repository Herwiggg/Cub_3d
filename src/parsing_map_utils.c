/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:33:55 by almichel          #+#    #+#             */
/*   Updated: 2024/11/18 19:30:32 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_errormap(char *str)
{
	int	k;

	k = ft_strlen(str);
	write(1, "Error\n", 6);
	write(1, str, k);
	exit (1);
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
    i = 0;
    if (flag == -1)
    {
        while (tab[i])
        {
            free(tab[i]);
            i++;
        }
	    free(tab);
        ft_errormap("Wrong color format\n");
    }
}

int is_a_char_map(char c)
{
    if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (0);
    return (-1);
}

int all_data_are_stocked(t_data *data)
{
    if (data->_no == NULL || data->_so == NULL || data->_we == NULL || data->_ea == NULL || data->_do == NULL || data->stock_f == NULL || data->stock_c == NULL) 
        return (-1);
    return (0);
}
