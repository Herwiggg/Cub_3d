/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:19:59 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 01:52:38 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_check(t_data *data)
{
	free_tab(data->file);
	free_tab(data->stock_f);
	free(data->_f);
	free(data->_c);
	free_tab(data->stock_c);
	free_tab(data->map);
	free(data->_ea);
	free(data->_so);
	free(data->_no);
	free(data->_we);
}

char	**ft_doublefree(char **tab, int k)
{
	int	i;

	i = 0;
	while (++i < k)
		free(tab[i]);
	free(tab);
	return (NULL);
}
