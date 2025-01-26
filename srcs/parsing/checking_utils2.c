/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:41:43 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 00:00:28 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	stock_data(t_data *data)
{
	while (data->file[data->i])
	{
		data->j = 0;
		data->found = 0;
		while (data->file[data->i][data->j] && data->found == 0)
		{
			stock_data3(data);
			if (data->found == 0)
			{
				if (is_a_char_map(data->file[data->i][data->j]) == 0)
					return (copy_map(data, data->i, data->j, &(data->map)));
				else
					stock_data2(data);
			}
			data->j++;
		}
		data->i++;
	}
	complete_checkup(data);
}

void	stock_data3(t_data *data)
{
	if (data->file[data->i][data->j] == 'N'
		&& data->file[data->i][data->j + 1] == 'O')
		check_textures(data, &data->count_no, data->_no);
	else if (data->file[data->i][data->j] == 'S'
		&& data->file[data->i][data->j + 1] == 'O')
		check_textures(data, &data->count_so, data->_so);
	else if (data->file[data->i][data->j] == 'W'
		&& data->file[data->i][data->j + 1] == 'E')
		check_textures(data, &data->count_we, data->_we);
	else if (data->file[data->i][data->j] == 'E'
		&& data->file[data->i][data->j + 1] == 'A')
		check_textures(data, &data->count_ea, data->_ea);
}

void	stock_data2(t_data *data)
{
	if (data->file[data->i][data->j] == 'F')
		check_colors_f(data, data->i, data->j);
	else if (data->file[data->i][data->j] == 'C')
		check_colors_c(data, data->i, data->j);
}

void	check_textures(t_data *data, int *count, char *text)
{
	(void)text;
	*count += 1;
	data->count_texts++;
	data->found++;
}
