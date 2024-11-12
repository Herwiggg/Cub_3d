/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:42:35 by loculy            #+#    #+#             */
/*   Updated: 2022/11/02 11:01:37 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	i = 0;
	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	if (cast_dst > cast_src)
	{
		while (len-- > 0)
			cast_dst[len] = cast_src[len];
	}
	else
	{
		while (i < len)
		{
			cast_dst[i] = cast_src[i];
			i++;
		}
	}
	return (dst);
}
