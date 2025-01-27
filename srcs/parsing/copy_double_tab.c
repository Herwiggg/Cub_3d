/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_double_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:27:14 by almichel          #+#    #+#             */
/*   Updated: 2025/01/27 01:58:38 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*my_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**copy_double_tab(char **src, char **dest)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (src[count] != NULL)
		count++;
	dest = (char **)malloc((count + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	while (i < count)
	{
		dest[i] = (char *)malloc((ft_strlen(src[i]) + 1) * sizeof(char));
		if (dest[i] == NULL)
			return (ft_doublefree(dest, i));
		my_strcpy(dest[i], src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

void	stock_info(t_jeu *jeu, t_data *data, t_info *info)
{
	jeu->floor_colors = copy_double_tab(data->stock_f, jeu->floor_colors);
	jeu->ceiling_colors = copy_double_tab(data->stock_c, jeu->ceiling_colors);
	info->path_e = copy_string_to_void(data->_ea);
	info->path_w = copy_string_to_void(data->_we);
	info->path_s = copy_string_to_void(data->_so);
	info->path_n = copy_string_to_void(data->_no);
}
