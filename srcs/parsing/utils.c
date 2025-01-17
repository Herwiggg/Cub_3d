/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:05:49 by elizohin          #+#    #+#             */
/*   Updated: 2025/01/17 21:20:18 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_tab_tab(char ***tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < 6)
		{
			free_tab(tab[i]);
			i++;
		}
		if (tab)
			free(tab);
	}
}

int	empty_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			j = 1;
			break ;
		}
		i++;
	}
	if (j == 1)
		return (0);
	return (1);
}

void	free_exit(t_jeu *jeu)
{
	free_tab(jeu->value);
	free_tab(jeu->map);
	free_tab(jeu->map_spaced);
	free_tab(jeu->ceiling_colors);
	free_tab(jeu->floor_colors);
	free_tab_tab(jeu->directions);
	free_tab(jeu->file_map);
}

int	ft_errormap(char *str)
{
	int	k;

	k = ft_strlen(str);
	(void)write(1, "Error\n", 6);
	(void)write(1, str, k);
	exit (1);
	return (1);
}

int    ft_count(char *str)
{
    int    count;
    int    i;

    i = 0;
    count = 0;
    while (str[i])
    {
        if ((str[i + 1] == ' ' || str[i + 1]
                || str[i + 1] == '\t' || str[i + 1] == '\n' || str[i + 1] == ',')
            && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&str[i] != ','))
            count++;
        i++;
    }
    return (count);
}

char    **ft_strcpy_modif(char **tab, char *str)
{
    int    k;
    int    i;
    int    j;

    i = 0;
    k = 0;
    j = 0;
    while (str[i])
    {
        j = 0;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != ',')
        tab[k][j++] = str[i++];
    tab[k++][j] = '\0';
        while (str[i] == ' ' || str[i] == '\t' || str[i] == ',')
            i++;
    }
    tab[k] = NULL;
    return (tab);
}

char    **ft_split_modif(char *str)
{
    char    **tab;
    int        k;
    int        i;
    int        j;

    i = 0;
    k = 0;
    j = 0;
    tab = malloc((ft_count(str) + 1) * sizeof(char *));
    if (!tab)
        return (NULL);
    while (k < ft_count(str))
    {
        while (str[i++] && str[i++] != ' ' && str[i++] != '\t' && str[i++] == ',')
            j++;
    tab[k++] = malloc((j + 1) * sizeof(char));
    j = 0;
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',')
            i++;
    }
    ft_strcpy_modif(tab, str);
    return (tab);
}

char	**ft_doublefree(char **tab, int k)
{
	int	i;

	i = -1;
	while (++i < k)
		free(tab[i]);
	free(tab);
	return (NULL);
}

void check_255_color(char **tab)
{
    int i;
    int flag;

    flag = 0;
    i = 0;
    while (tab[i])
    {
        if (ft_atoi(tab[i]) > 255)
        {
            flag = -1;
            break;
        }
        i++;
    }
    i = 0;
    if (flag == -1)
    {
        while (tab[i])
        {
            free(tab[i]);
            i++;
        }
	    free(tab);
        ft_errormap("Wrong color format\n");
    }
}

int is_a_char_map(char c)
{
    if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (0);
    return (-1);
}

int all_data_are_stocked(t_data *data)
{
    if (data->_no == NULL || data->_so == NULL || data->_we == NULL || data->_ea == NULL || data->_do == NULL || data->stock_f == NULL || data->stock_c == NULL) 
        return (-1);
    return (0);
}

void copy_map(char **file, int i, int j, char ***map)
{
    int count;
    int cp_i;
    int flag;
    int k;
    int flag_empty;

    flag_empty = 0;
    k = 0;
    flag = 0;
    j = 0;
    cp_i = i;
    count = 0;

    // Count the lines in the file starting from index `i`
    while (file[i])
    {
        j = 0;
        flag_empty = 0;
        while (file[i][j])
        {
            if (j == 0 && file[i][j] == '\n')
            {
                flag = 1;
                break;
            }
            if (file[i][j] != '\n' && file[i][j] != ' ' && file[i][j] != '\t')
                flag_empty = 1;
            j++;
        }
        if (flag_empty == 0)
        {
            ft_errormap("Wrong file format\n");
            break;
        }
        count++;
        i++;
    }
    if (flag == 1)
        ft_errormap("Wrong file format\n");

    // Allocate memory for the map
    *map = malloc((count + 1) * sizeof(char *));
    if (!(*map))
        return;

    i = cp_i;
    j = 0;

    // Allocate memory for each line in the map
    while (k < count)
    {
        j = 0;
        while (file[i][j])
            j++;
        (*map)[k] = malloc((j + 1) * sizeof(char));
        if (!(*map)[k])
        {
            ft_doublefree(*map, k);
            return;
        }
        i++;
        k++;
    }
    (*map)[k] = NULL; // Null-terminate the map array

    k = 0;
    i = cp_i;
    j = 0;
    while (k < count)
    {
        while (file[i][j])
        {
            (*map)[k][j] = file[i][j];
            j++;
        }
        (*map)[k][j] = '\0';
        j = 0;
        k++;
        i++;
    }
}