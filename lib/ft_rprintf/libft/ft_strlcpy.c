/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:40:52 by loculy            #+#    #+#             */
/*   Updated: 2022/11/01 11:02:05 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	a;
	unsigned int	i;

	i = 0;
	a = 0;
	while (src[i])
		i++;
	if (0 < dstsize)
	{
		while (src[a] && (a < dstsize - 1))
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (i);
}
