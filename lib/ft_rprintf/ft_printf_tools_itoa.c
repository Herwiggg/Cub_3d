/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_itoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:11:59 by loculy            #+#    #+#             */
/*   Updated: 2022/11/10 11:30:15 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pitoa_loop(unsigned int n, char *m, unsigned int size, int neg)
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

unsigned int	ft_pitoa_size(unsigned int use)
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

char	*ft_pitoa(unsigned int n)
{
	unsigned int	original;
	unsigned int	use;
	unsigned int	size;
	char			*m;

	original = n;
	use = original;
	size = ft_pitoa_size(use);
	m = malloc((size + 1) * sizeof(char));
	if (!m)
		return (0);
	return (ft_pitoa_loop(original, m, size, 0));
}
