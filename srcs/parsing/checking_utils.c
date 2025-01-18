/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:55:24 by almichel          #+#    #+#             */
/*   Updated: 2025/01/18 01:57:29 by almichel         ###   ########.fr       */
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
        (*tab)[index++] = file[cpi][cpj++];
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
        (*tab)[index++] = file[cpi][cpj++];
    (*tab)[index] = '\0';
}

