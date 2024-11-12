/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:20:27 by loculy            #+#    #+#             */
/*   Updated: 2023/06/29 21:10:54 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_loop(unsigned int n, char *m, unsigned int size, int neg)
{
	int	i;

	if (n == 0)
		m[0] = '0';
	m[size + neg] = '\0';
	i = size + neg - 1;
	while (n > 0)
	{
		m[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	i--;
	if (neg == 1)
		m[0] = '-';
	return (m);
}

static unsigned int	ft_itoa_size(unsigned int use)
{
	unsigned int	size;

	size = 0;
	while (use >= 10)
	{
		size++;
		use = use / 10;
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	original;
	unsigned int	use;
	unsigned int	size;
	int				neg;
	char			*m;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		original = -n;
	}
	else
		original = n;
	use = original;
	size = ft_itoa_size(use);
	m = malloc((size + neg + 1) * sizeof(char));
	if (!m)
		return (0);
	return (ft_itoa_loop(original, m, size, neg));
}
