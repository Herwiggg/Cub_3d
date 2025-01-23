/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fusion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:52:07 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 23:52:08 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fusion(t_jeu *jeu, t_info *info)
{
	info->posx = (double)(jeu->pos_i + 0.5);
	info->posy = (double)(jeu->pos_j + 0.5);
	info->path_e = jeu->directions[0][1];
	info->path_w = jeu->directions[1][1];
	info->path_s = jeu->directions[2][1];
	info->path_n = jeu->directions[3][1];
	info->worldmap = jeu->map_spaced;
	info->player = jeu->start_position;
	info->jeu = jeu;
}