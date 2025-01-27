/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:52:07 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 01:48:06 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fusion(t_jeu *jeu, t_info *info)
{
	info->posx = (double)(jeu->pos_i + 0.5);
	info->posy = (double)(jeu->pos_j + 0.5);
	info->worldmap = jeu->map_spaced;
	info->player = jeu->start_position;
	info->jeu = jeu;
}

void	*copy_string_to_void(const char *input)
{
	size_t	len;
	void	*buffer;

	if (!input)
		return (NULL);
	len = strlen(input);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, input, len + 1);
	return (buffer);
}
