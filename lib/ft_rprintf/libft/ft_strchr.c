/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:48:14 by loculy            #+#    #+#             */
/*   Updated: 2022/11/02 18:03:28 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cast_s;

	i = 0;
	cast_s = (char *)s;
	while (s[i])
	{
		if (cast_s[i] == (char)c)
			return (cast_s + i);
		i++;
	}
	if ((char)c == '\0')
		return (cast_s + i);
	return (0);
}
