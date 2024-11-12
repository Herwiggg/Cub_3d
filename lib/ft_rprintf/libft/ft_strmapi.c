/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:03:08 by loculy            #+#    #+#             */
/*   Updated: 2022/11/03 19:24:57 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*m;

	if (!s)
		return (0);
	m = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!m)
		return (0);
	i = 0;
	while (s[i])
	{
		m[i] = f(i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
