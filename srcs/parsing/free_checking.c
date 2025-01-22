/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:19:59 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 23:53:12 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    free_check(t_data *data)
{
    free_tab(data->file);
    free_tab(data->stock_f);
    free(data->_f);
    free(data->_c);
    free_tab(data->stock_c);
}
