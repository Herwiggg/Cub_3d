/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:41:43 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 01:39:45 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_colors_f(t_data *data, int i, int j)
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

void	check_colors_c(t_data *data, int i, int j)
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
