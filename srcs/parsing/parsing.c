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
	return (0);
}

int	check_direction(char *str, t_jeu *jeu)
{
	int			i;
	static char	*tab[7] = {"NO", "SO", "EA", "WE", "C", "F"};

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(str, tab[i], ft_strlen(tab[i]))
			&& ft_isspace(str[ft_strlen(tab[i])]) && jeu->ok[i] == 0)
		{
			jeu->directions[i] = ft_split(str, ' ');
		}
		i++;
	}
	return (0);
}


int	check_position(t_jeu *jeu)
{
	int		i;
	int		j;
	int		letter;

	i = 0;
	letter = 0;
	while (jeu->map_spaced[i])
	{
		j = 0;
		while (jeu->map_spaced[i][j])
		{
			if (ft_strchr("WNES", jeu->map_spaced[i][j]))
			{
				jeu->start_position = jeu->map_spaced[i][j];
				jeu->map_spaced[i][j] = '0';
				jeu->pos_i = i + letter++;
				jeu->pos_j = j;
			}
			j++;
		}
		i++;
	}
	return (letter != 1);
}

//compte le nombre de ligne de la map 
void	count_line(char *file, t_jeu *jeu)
{
	int		fd;
	char	*line;

	jeu->nb_line_file = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd, 0);
	while (line)
	{
		if (line == NULL)
			break ;
		jeu->nb_line_file++;
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
}

//jcopie le fichier grace a gnl
int	copy_file(char *file, t_jeu *jeu)
{
	char *(line);
	int (i) = 0;
	int (fd) = open(file, O_RDONLY);
	count_line(file, jeu);
	if (fd < 0 || read(fd, &line, 0) < 0)
		return (printf("Error\nThere is an error with the file !\n"), 1);
	jeu->file_map = malloc(sizeof(char *) * (jeu->nb_line_file + 1));
	if (!jeu->file_map)
		return (free(line), close(fd), 1);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == NULL)
			break ;
		jeu->file_map[i] = malloc(ft_strlen(line) + 1);
		if (!jeu->file_map[i])
			return (free(line), close(fd), 1);
		if (i == jeu->nb_line_file - 1)
			ft_strcpy_n(jeu->file_map[i], line);
		else
			ft_strcpy(jeu->file_map[i], line);
		free(line);
		i++;
	}
	return (jeu->file_map[i] = NULL, close (fd), 0);
}

int	copy_game_map_norm(t_jeu *jeu, int i, int count, int j)
{
	while (jeu->file_map[i] && empty_line(jeu->file_map[i]))
		i++;
	jeu->map = ft_calloc(sizeof(char *), ((jeu->nb_line_file - count) + 1));
	while (jeu->file_map[i])
	{
		if (jeu->file_map[i])
		{
			if (ft_strlen(jeu->file_map[i]) > jeu->longest_line)
				jeu->longest_line = ft_strlen(jeu->file_map[i]);
			jeu->map[j++] = ft_strdup(jeu->file_map[i]);
			jeu->nb_line_map++;
		}
		i++;
	}
	return (0);
}

//jcopie la map du jeu
int	copy_game_map(t_jeu *jeu)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (jeu->file_map[i])
	{
		if (!ft_strncmp(jeu->file_map[i], jeu->value[5],
				ft_strlen(jeu->value[5])))
		{
			i++;
			count++;
			break ;
		}
		count++;
		i++;
	}
	copy_game_map_norm(jeu, i, count, j);
	return (0);
}

int	ft_check_cub(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] != 'b' || argv[i - 2] != 'u' || argv[i - 3] != 'c' || argv[i
			- 4] != '.' || i <= 4)
	{
		return (-1);
	}
	return (1);
}
