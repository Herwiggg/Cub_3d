/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:08:21 by loculy            #+#    #+#             */
/*   Updated: 2022/11/17 19:39:44 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_phex_sz(unsigned long n)
{
	int	size;

	size = 0;
	while (n >= 16)
	{
		size++;
		n = n / 16;
	}
	size++;
	return (size);
}

char	*ft_phex(unsigned long n)
{
	int		size;
	char	*m;
	int		i;

	size = ft_phex_sz(n);
	m = malloc(size + 3 * sizeof(char));
	if (!m)
		return (0);
	m[0] = '0';
	m[1] = 'x';
	m[size + 2] = '\0';
	i = size + 1;
	while (n >= 16)
	{
		m[i] = "0123456789abcdef"[n % 16];
		n = n / 16;
		i--;
	}
	m[i--] = "0123456789abcdef"[n];
	return (m);
}

char	*ft_hithex(unsigned int n, char *ref, char hsh, t_flag flag)
{
	int		size;
	char	*m;
	int		i;

	size = ft_phex_sz(n);
	if (flag.prefix == 1 && n != 0)
		size += 2;
	m = malloc(size + 1 * sizeof(char));
	if (!m)
		return (0);
	m[size] = '\0';
	i = size - 1;
	while (n >= 16)
	{
		m[i] = ref[n % 16];
		n = n / 16;
		i--;
	}
	m[i--] = ref[n];
	if (flag.prefix == 1 && n != 0)
	{
		m[0] = '0';
		m[1] = hsh;
	}
	return (m);
}

char	*ft_ithex(unsigned int n, char *ref)
{
	int		size;
	char	*m;
	int		i;

	size = ft_phex_sz(n);
	m = malloc(size + 1 * sizeof(char));
	if (!m)
		return (0);
	m[size] = '\0';
	i = size - 1;
	while (n >= 16)
	{
		m[i] = ref[n % 16];
		n = n / 16;
		i--;
	}
	m[i--] = ref[n];
	return (m);
}
