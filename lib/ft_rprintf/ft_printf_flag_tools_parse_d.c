/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_tools_parse_d.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seya <seya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:06:15 by loculy            #+#    #+#             */
/*   Updated: 2023/06/24 00:03:48 by seya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fl_nj_d(t_of of, unsigned int s_sz, unsigned int out_sz,
			t_flag flag)
{
	unsigned int	i;
	unsigned int	o_sz;
	unsigned int	neg;

	o_sz = ft_strlen(of.s);
	i = out_sz - 1;
	neg = 0;
	if (of.s[0] == '-')
		neg = 1;
	while (s_sz > 0 + neg)
	{
		if (o_sz > 0 + neg)
			of.m[i--] = of.s[o_sz - 1];
		else
			of.m[i--] = '0';
		s_sz--;
		if (o_sz > 0)
			o_sz--;
	}
	ft_flag_pref(of, flag, i);
	return (of.m);
}

char	*ft_fl_j_d(t_of of, unsigned int s_sz, unsigned int i, t_flag flag)
{
	unsigned int	j;
	unsigned int	diff;
	unsigned int	o_sz;
	unsigned int	neg;

	o_sz = ft_strlen(of.s);
	neg = 0;
	diff = s_sz - o_sz;
	if (flag.x != '0')
		of.m[i++] = '0';
	if (flag.x != '0')
		of.m[i++] = flag.x;
	if (of.s[0] == '-')
		of.m[i++] = '-';
	if (of.s[0] == '-')
		neg = 1;
	j = 0 + neg;
	while (i < s_sz)
	{
		if (i < diff + neg)
			of.m[i++] = '0';
		else
			of.m[i++] = of.s[j++];
	}
	return (of.m);
}

unsigned int	ft_get_ouszd(char *s, t_flag flag, unsigned int *out_sz)
{
	unsigned int	s_sz;
	unsigned int	o_sz;
	unsigned int	neg;
	unsigned int	x;
	t_stzd			stzd;

	neg = 0;
	x = 0;
	if (flag.x != '0')
		x = 2;
	if (s[0] == '-')
		neg = 1;
	stzd.s = s;
	stzd.out_sz = out_sz;
	stzd.s_sz = &s_sz;
	stzd.o_sz = &o_sz;
	stzd.neg = &neg;
	stzd.x = &x;
	stzd = ft_flag_ouszd_a(stzd, flag);
	stzd = ft_flag_ouszd_b(stzd, flag);
	return (s_sz);
}

char	*ft_fl_m_d(char *s, t_flag flag, unsigned int *out_sz)
{
	char			*m;
	unsigned int	s_sz;
	unsigned int	i;
	t_of			of;
	t_fn			fn;

	i = 0;
	s_sz = ft_get_ouszd(s, flag, out_sz);
	m = malloc(*out_sz * sizeof(char) + 1);
	if (!m)
		return (0);
	m = ft_fl_init(m, *out_sz);
	if ((flag.blank == 1 || (flag.positive == 1 && flag.justify == 1))
		&& s[0] != '-')
		i = 1;
	of.m = m;
	of.s = s;
	if (flag.justify == 1)
		m = ft_fl_j_d(of, s_sz + i, i, flag);
	else
		m = ft_fl_nj_d(of, s_sz, *out_sz, flag);
	fn.out_sz = out_sz;
	fn.s_sz = s_sz;
	fn.i = i;
	return (ft_finalize(s, m, flag, fn));
}
