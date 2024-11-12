/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:01:10 by loculy            #+#    #+#             */
/*   Updated: 2022/11/02 18:06:08 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cast_s;

	i = ft_strlen(s);
	cast_s = (char *)s;
	if ((char)c == '\0')
		return (cast_s + i);
	i -= 1;
	while (0 <= i)
	{
		if (cast_s[i] == (char)c)
			return (cast_s + i);
		i--;
	}
	return (0);
}
