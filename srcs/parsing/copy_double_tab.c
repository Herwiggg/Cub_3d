/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_double_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:27:14 by almichel          #+#    #+#             */
/*   Updated: 2025/01/26 22:39:20 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *my_strcpy(char *dest, const char *src) 
{
    size_t i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char    **copy_double_tab(char **src, char **dest) 
{
    size_t count;
    size_t  i;

    i = 0;
    count = 0;
    while (src[count] != NULL)
        count++;
    dest = (char **)malloc((count + 1) * sizeof(char *));
    if (dest == NULL)
        return NULL;
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