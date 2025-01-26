/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizohin <elizohin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:58:22 by elizohin          #+#    #+#             */
/*   Updated: 2024/09/02 16:08:34 by elizohin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define ERRORFILE "Error\nValue Error\n"

int	malloc_space_map(t_jeu *jeu)
{
	int	i;

	i = 0;
	jeu->map_spaced = malloc(sizeof(char *) * (jeu->nb_line_map + 3));
	if (!jeu->map_spaced)
		return (1);
	while (i < jeu->nb_line_map + 2)
	{
		jeu->map_spaced[i] = ft_calloc(sizeof(char), (jeu->longest_line + 4));
		if (!jeu->map_spaced[i])
			return (1);
		ft_memset(jeu->map_spaced[i], ' ', (jeu->longest_line + 2));
		i++;
	}
	jeu->map_spaced[i] = NULL;
	return (0);
}

int	parsing_map(t_jeu *jeu)
{
	int	i;

	i = 0;
	malloc_space_map(jeu);
	while (jeu->map[i])
	{
		ft_memcpy(&jeu->map_spaced[i + 1][1], jeu->map[i],
			ft_strlen(jeu->map[i]));
		i++;
	}
	return (0);
}

int	copy_map_value(char *file, t_jeu *jeu)
{
	char *(line);
	int (fd) = open(file, O_RDONLY);
	int (i) = 0;
	if (fd < 0 || read(fd, &line, 0) < 0)
		return (printf("Error\nThere is an error with the file !\n"), 0);
	jeu->value = ft_calloc(sizeof(*jeu->value), 7);
	if (!jeu->value)
		return (1);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line && !empty_line(line))
		{
			jeu->value[i] = malloc(ft_strlen(line) + 1);
			if (!jeu->value[i])
				return (1);
			ft_strcpy(jeu->value[i++], line);
		}
		free(line);
		if (i == 6 || line == NULL)
			break ;
	}
	if (i != 6)
		return (get_next_line(fd, 1), printf(ERRORFILE), close(fd), 1);
	return (get_next_line(fd, 1), close (fd), 0);
}

int	check_map_value(t_jeu *jeu)
{
	int	i;

	i = 0;
	jeu->directions = ft_calloc(sizeof(char **), 7);
	while (jeu->value[i])
	{
		if (check_direction(jeu->value[i], jeu))
			return (printf("Error\nValue Error !\n"), 1);
		i++;
	}
	if (check_rgb_ceiling(jeu) || check_rgb_floor(jeu))
        return (printf("Error\nValue RGB\n"));
	return (0);
}

int    check_direction(char *str, t_jeu *jeu)
{
    int            i;
    int            check;
    static char    *tab[7] = {"NO", "SO", "EA", "WE", "C", "F"};

    i = 0;
    check = 0;
    while (tab[i])
    {
        if (!ft_strncmp(str, tab[i], ft_strlen(tab[i]))
            && ft_isspace(str[ft_strlen(tab[i])]) && jeu->ok[i] == 0)
        {
            jeu->directions[i] = ft_split(str, ' ');
            jeu->ok[i] = 1;
            check = 1;
        }
        i++;
    }
    if (check == 0)
        return (1);
    return (0);
}
