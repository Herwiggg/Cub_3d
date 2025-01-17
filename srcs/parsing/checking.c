/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:45:43 by almichel          #+#    #+#             */
/*   Updated: 2025/01/17 21:06:27 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_map(char **map, t_data *data)
{
    int i;
    int j;
    int flag_start;

    flag_start = 0;
    i = 1;
    j = 0;
    if (check_first_last_wall(map) == -1)
        ft_errormap("Bad wall(s)\n");
    while(map[i + 1])
    {
        j = 0;
        while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
            j++;
        while (map[i][j] && j < del_space_map(map[i]))
        {
            if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
            {
                if (check_spaces(map, i, j) == -1)
                    ft_errormap("Bad Wall(s)\n");
                if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                {
                    flag_start++;
                    if (flag_start > 1)
                        ft_errormap("Bad start map\n");
                    data->player.x = j;
                    data->player.y = i;
                    data->player.pos = map[i][j];
                }
            }
            else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != ' ' && map[i][j] != '\t')
                ft_errormap("Bad map\n");
            j++;
        }
        i++;        
    }
    if (flag_start != 1)
        ft_errormap("Bad start map\n");
    return (0);
}


int check_first_last_wall(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (i == 0 && map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '1' && map[i][j] != '\n')
            {
                return (-1);
            }
            j++;
        }
        i++;
    }
    i--;
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '1' && map[i][j] != '\n')
        {
            return (-1);
        }
        j++;
    }
    return (0);
}

int del_space_map(char *str)
{
    int i;

    i = 0;

    while (str[i])
        i++;
    while (i > 0 && str[i] != '\n' && str[i] != ' ' && str[i] != '\t')
        i--;
    return (i);
}

int check_spaces(char **map, int i, int j)
{
    if (map[i + 1][j] == ' ' || map[i + 1][j] == '\t' || map[i + 1][j] == '\n' || map[i + 1][j] == '\0')
        return (-1);
    if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t' || map[i - 1][j] == '\n' || map[i - 1][j] == '\0')
        return (-1);
    if (map[i][j + 1] == ' ' || map[i][j + 1] == '\t' || map[i][j + 1] == '\n' || map[i][j + 1] == '\0')
        return (-1);
    if (map[i][j - 1] == ' ' || map[i][j - 1] == '\t' || map[i][j - 1] == '\n' || map[i][j - 1] == '\0')
        return (-1);
    return (0);
}
