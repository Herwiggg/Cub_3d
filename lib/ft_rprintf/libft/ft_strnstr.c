/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:24:45 by loculy            #+#    #+#             */
/*   Updated: 2022/11/02 15:18:43 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	a;
	unsigned int	b;

	a = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[a] && a < len)
	{
		b = 0;
		while (haystack[a + b] && haystack[a + b] == needle[b] && a + b < len)
			b++;
		if (needle[b] == '\0')
			return ((char *)&haystack[a]);
		a++;
	}
	return (0);
}
