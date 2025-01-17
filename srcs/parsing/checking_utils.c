/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:55:24 by almichel          #+#    #+#             */
/*   Updated: 2025/01/17 21:51:24 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_check_retour(char *dest)
{
	int		i;
	char	*new_tab;

	i = 0;
	while (dest[i] != '\0')
		i++;
	if (dest[i - 1] != '\n')
	{
		new_tab = malloc((ft_strlen(dest) + 2) * sizeof(char));
		if (!new_tab)
			return (NULL);
		i = 0;
		while (dest[i] != '\0')
		{
			new_tab[i] = dest[i];
			i++;
		}
		new_tab[i] = '\n';
		i++;
		new_tab[i] = '\0';
		free(dest);
		return (new_tab);
	}
	return (dest);
}

char	**ft_stock(char **dest, char *argv, int fd, int size)
{
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (size < 9)
	{
		ft_errormap("invalide number of line, can't be a valid map\n");
		return (NULL);
	}
	dest = malloc((size + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest[size] = NULL;
	while (i < size)
	{
		dest[i] = get_next_line(fd, 0);
		if (dest[0] == NULL)
			return (NULL);
		dest[i] = ft_check_retour(dest[i]);
		if (!dest)
			return (NULL);
		i++;
	}
	close(fd);
	return (dest);
}

char	**ft_read_and_stock(char *argv, t_data *data)
{
	int		size;
	char	*temp;
	int		fd;
	char	**dest;

	dest = NULL;
	size = 0;
	fd = open(argv, O_RDONLY);
	data->readed = read(fd, 0, 0);
	if (fd < 0 || data->readed < 0)
	{
		ft_errormap("Invalid file\n");
		close(fd);
		return (NULL);
	}
	while (1)
	{
		temp = get_next_line(fd, 0);
		if (temp == NULL)
			break ;
		size++;
		free(temp);
	}
	close(fd);
	return (ft_stock(dest, argv, fd, size));
}

void stock_data(t_data *data)
{
    int i;
    int count_texts;
    int count_colors;
    int j;
    int found;

    found = 1;
    j = 0;
    count_texts = 0;
    count_colors = 0;
    i = 0;
    while (data->file[i])
    {
        j = 0;
        found = 0;
        while (data->file[i][j] && found == 0)
        {
            if (data->file[i][j] == 'N' && data->file[i][j + 1] == 'O')
            {
                if (data->_no != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_no), i, j);
                count_texts++;
                found++;
            }
            else if (data->file[i][j] == 'S' && data->file[i][j + 1] == 'O')
            {
                if (data->_so != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_so), i, j);
                count_texts++;
                found++;
            }
            else if (data->file[i][j] == 'W' && data->file[i][j + 1] == 'E')
            {
                if (data->_we != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_we), i, j);
                count_texts++;
                found++;
            }
            else if (data->file[i][j] == 'E' && data->file[i][j + 1] == 'A')
            {
                if (data->_ea != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_ea), i, j);
                count_texts++;
                found++;
            }
            else if (data->file[i][j] == 'D' && data->file[i][j + 1] == 'O')
            {
                if (data->_do != NULL)
                    ft_errormap("Wrong textures format\n");
                stock_texts(data->file, &(data->_do), i, j);
                count_texts++;
                found++;
            }
            else if(data->file[i][j] == 'F')
            {
                if (data->stock_f != NULL)
                    ft_errormap("Wrong colors format\n");
                stock_colors(data->file, &(data->_f), i, j);
                check_color(data->_f);
                data->stock_f = ft_split_modif(data->_f);
                free(data->_f);
                check_255_color(data->stock_f);
                count_colors++;
                found++;
            }
            else if (data->file[i][j] == 'C')
            {
                if (data->stock_c != NULL)
                    ft_errormap("Wrong colors format\n");
                stock_colors(data->file, &(data->_c), i, j);
                check_color(data->_c);
                data->stock_c = ft_split_modif(data->_c);
                free(data->_c);
                check_255_color(data->stock_c);
                count_colors++;
                found++;
            }
            else if (is_a_char_map(data->file[i][j]) == 0)
            {
                {
                    copy_map(data->file, i, j, &(data->map));
                    return;
                }
            }
            j++;
        }
        i++;
    }
	if (all_data_are_stocked(data) == -1)
                    ft_errormap("Wrong file format\n");
    if (count_texts != 5)
    {
        ft_errormap("Wrong textures format\n");
        return;
    }
     if (count_colors != 2)
    {
        ft_errormap("Wrong colors format\n");
        return;
    }
}

void stock_texts(char **file, char **tab, int i, int j)
{
    int cpi;
    int cpj;
    int count;
    int index;

    count = 0;
    index = 0;
    cpi = i;
    j = j + 2;
    cpj = j;

    while (file[i][j] && (file[i][j] == ' ' || file[i][j] == '\t'))
        j++;
    while (file[i][j])
    {
        j++;
        count++;
    }

    *tab = malloc((count) * sizeof(char));
    if (!(*tab))
        return;

    while (file[cpi][cpj] && (file[cpi][cpj] == ' ' || file[cpi][cpj] == '\t'))
        cpj++;
    while (file[cpi][cpj] && file[cpi][cpj] != '\n')
    {
        (*tab)[index] = file[cpi][cpj];
        index++;
        cpj++;
    }
    (*tab)[index] = '\0';
}

void stock_colors(char **file, char **tab, int i, int j)
{
    int cpi;
    int cpj;
    int count;
    int index;

    count = 0;
    index = 0;
    cpi = i;
    j = j + 1;
    cpj = j;

    while (file[i][j] && (file[i][j] == ' ' || file[i][j] == '\t'))
        j++;
    while (file[i][j])
    {
        j++;
        count++;
    }
    *tab = malloc((count) * sizeof(char));
    if (!(*tab))
        return;

    while (file[cpi][cpj] && (file[cpi][cpj] == ' ' || file[cpi][cpj] == '\t'))
        cpj++;
    while (file[cpi][cpj] && file[cpi][cpj] != '\n')
    {
        (*tab)[index] = file[cpi][cpj];
        index++;
        cpj++;
    }
    (*tab)[index] = '\0';
}

void    check_color(char *color)
{
    int i;
    int count;
    int flag;

    flag = 0;
    count = 0;
    i = 0;

    while (color[i])
    {
        if (color[i] == ',')
            count++;
        else if ((color[i] < '0' || color[i] > '9') && (color[i] != ' ' && color[i] != '\t'))
            count = 5;
        i++;
    }
    if (count != 2)
        ft_errormap("Wrong color format\n");
    i = 0;
    count = 0;
    while (color[i])
    {
        if (color[i] != ',' && color[i] != ' ' && color[i] != '\t')
        {
            count++;
        }
        else
            count = 0;
        if (count > 3)
            break;
        i++;
    }
    i = 0;
    while (color[i])
    {
        if (color[i] == ',' && flag == 0)
        {
            flag = -1;
            break;
        }
        if (color[i] == ',')
            flag = 0;
        else if (color[i] >= '0' && color[i] <= '9')
            flag++;
        i++;

    }
     if (count > 3)
        ft_errormap("Wrong color format\n");
    else if (flag == -1 || flag == 0)
        ft_errormap("Wrong color format\n");


}
