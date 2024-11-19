/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:10:16 by almichel          #+#    #+#             */
/*   Updated: 2024/11/19 14:35:28 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		dest[i] = get_next_line(fd);
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
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		size++;
		free(temp);
	}
	close(fd);
	return (ft_stock(dest, argv, fd, size));
}

