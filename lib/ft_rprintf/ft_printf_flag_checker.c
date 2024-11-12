/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:19:21 by loculy            #+#    #+#             */
/*   Updated: 2022/11/15 19:00:27 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_start_checker(char ff)
{
	if (ff == '0' || ff == '#' || ff == ' '
		|| ff == '+' || ff == '-')
		return (1);
	else
		return (0);
}

int	ft_flag_checker(char ff)
{
	if (ft_isdigit(ff) == 1 || ff == '#' || ff == '.' || ff == ' '
		|| ff == '+' || ff == '-')
		return (1);
	else
		return (0);
}

int	ft_type_checker(char ff)
{
	if (ff == 'c' || ff == 's' || ff == 'p' || ff == 'd'
		|| ff == 'i' || ff == 'u' || ff == 'x' || ff == 'X'
		|| ff == '%')
		return (1);
	else
		return (0);
}

int	ft_flag_valider(char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i] && ft_flag_checker(fmt[i]))
		i++;
	if (ft_type_checker(fmt[i - 1]) || ft_type_checker(fmt[i]))
		return (1);
	return (0);
}
