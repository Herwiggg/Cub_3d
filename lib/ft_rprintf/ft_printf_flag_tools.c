/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:04:47 by loculy            #+#    #+#             */
/*   Updated: 2022/11/21 12:16:02 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_stzd	ft_flag_ouszd_b(t_stzd stzd, t_flag flag)
{
	if (flag.after + *(stzd.neg) > *(stzd.o_sz) && flag.after
		>= ft_strlen(stzd.s))
		*(stzd.s_sz) = flag.after + *(stzd.neg);
	if (flag.value > *(stzd.o_sz) && flag.justify == 1)
		*(stzd.out_sz) = flag.value;
	if (flag.before + *(stzd.neg) > *(stzd.s_sz) && flag.before
		>= ft_strlen(stzd.s))
		*(stzd.out_sz) = flag.before;
	if (!(flag.value + *(stzd.x) > ft_strlen(stzd.s) + *(stzd.x)
			&& flag.zero == 1) && *(stzd.x) == 2)
		*(stzd.s_sz) = *(stzd.s_sz) + *(stzd.x);
	else if (!(flag.value + 1 > ft_strlen(stzd.s) + *(stzd.x) && flag.zero == 1)
		&& *(stzd.x) == 2)
		*(stzd.s_sz) = *(stzd.s_sz) + 1;
	if (*(stzd.out_sz) < *(stzd.s_sz))
		*(stzd.out_sz) = *(stzd.s_sz);
	if ((flag.blank == 1 || flag.positive == 1) && stzd.s[0] != '-'
		&& *(stzd.out_sz) <= *(stzd.s_sz))
		*(stzd.out_sz) = *(stzd.out_sz) + 1;
	return (stzd);
}

t_stzd	ft_flag_ouszd_a(t_stzd stzd, t_flag flag)
{
	*(stzd.o_sz) = ft_strlen(stzd.s);
	if (flag.after >= ft_strlen(stzd.s))
		*(stzd.o_sz) += *(stzd.neg);
	*(stzd.s_sz) = *(stzd.o_sz);
	*(stzd.out_sz) = *(stzd.o_sz);
	if (flag.value + *(stzd.neg) > *(stzd.o_sz) && flag.justify == 0
		&&flag.value >= ft_strlen(stzd.s))
		*(stzd.out_sz) = flag.value;
	if (flag.value > *(stzd.o_sz) && flag.justify == 0 && flag.zero == 1)
	{
		if ((flag.blank == 1 || flag.positive == 1) && stzd.s[0] != '-')
			*(stzd.s_sz) = flag.value - 1;
		else
			*(stzd.s_sz) = flag.value;
	}
	if (flag.precision == 1 && flag.after == 0 && ft_strlen(stzd.s) == 1
		&& stzd.s[0] == '0')
	{
		*(stzd.s_sz) = 0;
		*(stzd.out_sz) = 0;
	}
	return (stzd);
}

void	ft_flag_pref(t_of of, t_flag flag, int i)
{
	if (flag.x != '0')
		of.m[i + 1] = '0';
	if (flag.x != '0')
		of.m[i + 2] = flag.x;
	if (of.s[0] == '-')
		of.m[i] = '-';
}

char	*ft_finalize(char *s, char *m, t_flag flag, t_fn fn)
{
	if (flag.positive == 1 && s[0] != '-')
	{
		if (flag.justify == 1)
			m[0] = '+';
		else
			m[*(fn.out_sz) - (fn.s_sz + fn.i) - 1] = '+';
	}
	if (flag.blank == 1 && s[0] != '-')
		m[0] = ' ';
	return (m);
}

unsigned int	ft_flag_size(char *s, int nt)
{
	unsigned int	i;

	i = 0;
	if (nt == 1)
		return (1);
	if (nt == 2)
		return (6);
	while (s[i])
		i++;
	return (i);
}
