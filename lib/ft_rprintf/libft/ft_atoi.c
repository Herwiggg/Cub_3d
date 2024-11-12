/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:54:57 by loculy            #+#    #+#             */
/*   Updated: 2022/11/03 17:11:11 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_atoi(const char *str, int i, int neg)
{
	int	res;

	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		res = -res;
	return (res);
}

static int	ft_checkstart_atoi(const char *str, int i)
{
	int		neg;
	char	c;

	neg = 0;
	c = str[i];
	while (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		i++;
		c = str[i];
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	return (ft_calc_atoi(str, i, neg));
}

int	ft_atoi(const char *str)
{
	if (ft_strlen(str) == 0)
		return (0);
	else
		return (ft_checkstart_atoi(str, 0));
}
