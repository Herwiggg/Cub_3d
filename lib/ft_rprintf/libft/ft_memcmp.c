/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:02:01 by loculy            #+#    #+#             */
/*   Updated: 2022/11/02 15:24:51 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*sa;
	unsigned char	*sb;

	i = 0;
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (sa[i] == sb[i] && 0 < n - 1)
	{
		i++;
		n--;
	}
	return (sa[i] - sb[i]);
}
