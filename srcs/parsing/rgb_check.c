/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:48:51 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 01:54:52 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_rgb_ceiling(t_jeu *jeu)
{
	int	i;

	i = 0;
	if (!jeu->directions[4])
		return (1);
	i = 0;
	while (i != 3)
	{
		i++;
	}
	return (0);
}

int	check_rgb_floor(t_jeu *jeu)
{
	int	i;

	i = 0;
	if (!jeu->directions[5])
		return (1);
	i = 0;
	while (i != 3)
	{
		i++;
	}
	return (0);
}

int	convert_rgb_to_color(char **rgb)
{
	int	color;
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void	convert_color(t_info *info, t_jeu *jeu)
{
	info->ceiling = convert_rgb_to_color(jeu->ceiling_colors);
	info->floor = convert_rgb_to_color(jeu->floor_colors);
}
