/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:45:43 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 23:55:10 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(char **map, t_data *data)
{
	int	i;
	int	j;

	data->flag_start = 0;
	i = 1;
	if (check_first_last_wall(map) == -1)
		ft_errormap2("Bad wall(s)\n", data);
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
			j++;
		check_map2(map, i, j, data);
		i++;
	}
	if (data->flag_start != 1)
		ft_errormap2("Bad start map\n", data);
}

void	check_map2(char **map, int i, int j, t_data *data)
{
	while (map[i][j] && j < del_space_map(map[i]))
	{
		if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
		{
			if (check_spaces(map, i, j) == -1)
				ft_errormap2("Bad Wall(s)\n", data);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				data->flag_start += 1;
				if (data->flag_start > 1)
					ft_errormap2("Bad start map\n", data);
			}
		}
		else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
			&& map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != ' '
						&& map[i][j] != '\t')
			ft_errormap2("Bad map\n", data);
		j++;
	}
}

int	check_first_last_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != ' ' && map[i][j] != '\t'
					&& map[i][j] != '1' && map[i][j] != '\n')
				return (-1);
			j++;
		}
		i++;
	}
	i--;
	j = 0;
	return (check_first_last_wall2(map, i, j));
}

int	check_first_last_wall2(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] != ' ' && map[i][j] != '\t'
				&& map[i][j] != '1' && map[i][j] != '\n')
			return (-1);
		j++;
	}
	return (0);
}

int	del_space_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0 && str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
		i--;
	return (i);
}
