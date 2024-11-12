/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:59:18 by loculy            #+#    #+#             */
/*   Updated: 2022/11/18 17:10:06 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fg_x(unsigned int a, t_plist **out, int *error, t_flag flag)
{
	unsigned int	out_sz;
	unsigned long	n;
	char			*m;
	char			*f;
	t_plist			*new;

	out_sz = 0;
	n = (unsigned long)a;
	f = ft_ithex(n, "0123456789abcdef");
	if (f == NULL)
		return (ft_error_return(error, 1));
	if (flag.prefix == 1 && !(ft_strlen(f) == 1 && f[0] == '0'))
		flag.x = 'x';
	m = ft_fl_m_d(f, flag, &out_sz);
	free(f);
	if (m == NULL)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
		return (ft_error_return_free(error, 1, m));
	new->size = out_sz;
	ft_plstadd_back(out, new);
	return (out_sz);
}

int	ft_fg_xx(unsigned int a, t_plist **out, int *error, t_flag flag)
{
	unsigned int	out_sz;
	unsigned long	n;
	char			*m;
	char			*f;
	t_plist			*new;

	out_sz = 0;
	n = (unsigned long)a;
	f = ft_ithex(n, "0123456789ABCDEF");
	if (f == NULL)
		return (ft_error_return(error, 1));
	if (flag.prefix == 1 && !(ft_strlen(f) == 1 && f[0] == '0'))
		flag.x = 'X';
	m = ft_fl_m_d(f, flag, &out_sz);
	free(f);
	if (m == NULL)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
		return (ft_error_return_free(error, 1, m));
	new->size = out_sz;
	ft_plstadd_back(out, new);
	return (out_sz);
}
