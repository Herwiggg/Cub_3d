/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 01:57:08 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 01:43:27 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_color(char *color, t_data *data)
{
	int	i;
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	i = 0;
	check_color2(color, &count, data);
	while (color[i])
	{
		if (color[i] == ',' && flag == 0)
			ft_errormap2("Wrong color format\n", data);
		if (color[i] == ',')
			flag = 0;
		else if (color[i] >= '0' && color[i] <= '9')
			flag++;
		i++;
	}
	if (count > 3)
		ft_errormap2("Wrong color format\n", data);
	else if (flag == -1 || flag == 0)
		ft_errormap2("Wrong color format\n", data);
}

void	check_color2(char *color, int *count, t_data *data)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (color[i] == ',')
			*count += 1;
		else if ((color[i] < '0' || color[i] > '9')
			&& (color[i] != ' ' && color[i] != '\t'))
			*count = 5;
		i++;
	}
	if (*count != 2)
		ft_errormap2("Wrong color format\n", data);
	i = 0;
	*count = 0;
	check_color3(color, i, count);
}

void	check_color3(char *color, int i, int *count)
{
	while (color[i])
	{
		if (color[i] != ',' && color[i] != ' ' && color[i] != '\t')
			*count += 1;
		else
			*count = 0;
		if (*count > 3)
			break ;
		i++;
	}
}

void	complete_checkup(t_data *data)
{
	if (data->count_ea > 1 || data->count_we > 1
		|| data->count_no > 1 || data->count_so > 1)
		ft_errormap2("Wrong textures format\n", data);
	if (data->count_texts != 4)
		ft_errormap2("Wrong textures format\n", data);
	if (data->count_colors != 2)
		ft_errormap2("Wrong colors format\n", data);
}

int	check_spaces(char **map, int i, int j)
{
	if (map[i + 1][j] == ' ' || map[i + 1][j] == '\t'
		|| map[i + 1][j] == '\n' || map[i + 1][j] == '\0')
		return (-1);
	if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'
			|| map[i - 1][j] == '\n' || map[i - 1][j] == '\0')
		return (-1);
	if (map[i][j + 1] == ' ' || map[i][j + 1] == '\t'
			|| map[i][j + 1] == '\n' || map[i][j + 1] == '\0')
		return (-1);
	if (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'
			|| map[i][j - 1] == '\n' || map[i][j - 1] == '\0')
		return (-1);
	return (0);
}
