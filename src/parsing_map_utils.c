/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:33:55 by almichel          #+#    #+#             */
/*   Updated: 2024/11/15 17:00:35 by almichel         ###   ########.fr       */
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
