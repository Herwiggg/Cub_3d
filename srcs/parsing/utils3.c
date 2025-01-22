/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:30:12 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 18:13:56 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int is_a_char_map(char c)
{
    if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (0);
    return (-1);
}

int all_data_are_stocked(t_data *data)
{
    if (data->_no == NULL || data->_so == NULL || data->_we == NULL || data->_ea == NULL || data->stock_f == NULL || data->stock_c == NULL) 
        return (-1);
    return (0);
}

int	ft_check_cub(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] != 'b' || argv[i - 2] != 'u' || argv[i - 3] != 'c' || argv[i
			- 4] != '.' || i <= 4)
	{
		return (-1);
	}
	return (1);
}
