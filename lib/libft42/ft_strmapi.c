/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:29:20 by almichel          #+#    #+#             */
/*   Updated: 2023/11/14 13:29:29 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;

	i = 0;
	dest = strdup(s);
	if (!dest)
		return (NULL);
	while (dest[i])
	{
		dest[i] = (*f)(i, dest[i]);
		i++;
	}
	return (dest);
}
