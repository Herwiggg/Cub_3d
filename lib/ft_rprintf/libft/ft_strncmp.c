/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:01:02 by loculy            #+#    #+#             */
/*   Updated: 2022/11/01 17:33:10 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*sa;
	unsigned char	*sb;

	i = 0;
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	while (sa[i] && sa[i] == sb[i] && 0 < n)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (sa[i] - sb[i]);
}
