/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:24:26 by almichel          #+#    #+#             */
/*   Updated: 2023/11/14 15:04:31 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
	{
		count = 1;
		return (count);
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			count;
	long int	nb;

	nb = n;
	count = ft_count(n);
	result = malloc ((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[count--] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		result[0] = '-';
	}
	while (nb > 0)
	{
		result[count--] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (result);
}
/*
#include <stdio.h>
int main()
{
	int	n = -1;
	printf("%s\n", ft_itoa(n));
}*/