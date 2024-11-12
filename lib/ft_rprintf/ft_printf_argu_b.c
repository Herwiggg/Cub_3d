/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_argu_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:06:52 by loculy            #+#    #+#             */
/*   Updated: 2022/11/16 19:38:38 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_w_x(unsigned int a, t_plist **out, int *error)
{
	unsigned long	n;
	char			*m;
	t_plist			*new;

	n = (unsigned long)a;
	m = ft_ithex(n, "0123456789abcdef");
	if (m == 0)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
	{
		free(m);
		return (ft_error_return(error, 1));
	}
	new->size = ft_strlen(m);
	ft_plstadd_back(out, new);
	return (ft_strlen(m));
}

int	ft_w_xx(unsigned int a, t_plist **out, int *error)
{
	unsigned long	n;
	char			*m;
	t_plist			*new;

	n = (unsigned long)a;
	m = ft_ithex(n, "0123456789ABCDEF");
	if (m == 0)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
	{
		free(m);
		return (ft_error_return(error, 1));
	}
	new->size = ft_strlen(m);
	ft_plstadd_back(out, new);
	return (ft_strlen(m));
}
