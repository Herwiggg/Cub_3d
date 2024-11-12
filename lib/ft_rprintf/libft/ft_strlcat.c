/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:16:36 by loculy            #+#    #+#             */
/*   Updated: 2022/11/02 12:27:15 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	if (src[0] == '\0')
		return (ft_strlen(dst));
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[a])
		a++;
	if (dstsize == 0 || dstsize <= a)
		return (dstsize + ft_strlen(src));
	while (src[b] && b < (dstsize - a - 1))
	{
		dst[a + b] = src[b];
		b++;
	}
	dst[a + b] = '\0';
	return (a + ft_strlen(src));
}
