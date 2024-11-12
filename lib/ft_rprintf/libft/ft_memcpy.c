/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:36:15 by loculy            #+#    #+#             */
/*   Updated: 2022/11/02 11:00:00 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	i = 0;
	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < len)
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	return (dst);
}
