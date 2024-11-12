/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_tools_parse_s.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seya <seya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:06:15 by loculy            #+#    #+#             */
/*   Updated: 2023/06/24 00:03:30 by seya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fl_init(char *m, unsigned int out_sz)
{
	unsigned int	i;

	i = 0;
	while (i < out_sz + 1)
		m[i++] = ' ';
	m[out_sz] = '\0';
	return (m);
}

char	*ft_fl_nj_s(char *s, char *m, unsigned int s_sz, unsigned int out_sz)
{
	unsigned int	i;

	i = out_sz - 1;
	while (s_sz > 0)
	{
		m[i] = s[s_sz - 1];
		i--;
		s_sz--;
	}
	return (m);
}

char	*ft_fl_j_s(char *s, char *m, unsigned int s_sz)
{
	unsigned int	i;

	i = 0;
	while (i < s_sz)
	{
		m[i] = s[i];
		i++;
	}
	return (m);
}

unsigned int	ft_get_ouszs(char *s, t_flag flag, int nt, unsigned int *out_sz)
{
	unsigned int	s_sz;

	s_sz = ft_flag_size(s, nt);
	*out_sz = flag.before;
	if (flag.precision == 1 && flag.after < s_sz && nt != 1)
		s_sz = flag.after;
	if ((flag.precision == 1 && flag.before < s_sz))
		*out_sz = s_sz;
	if (flag.precision == 1 && flag.before == 0 && flag.after == 0 && nt != 1)
		*out_sz = 0;
	if (flag.precision == 0 && flag.value > 0)
		*out_sz = flag.value;
	if (flag.precision == 0 && (flag.value < s_sz || flag.value == 0))
		*out_sz = s_sz;
	if (nt == 2 && s_sz < 6 && flag.precision == 0)
		s_sz = 6;
	if (nt == 2 && *out_sz < 6 && flag.precision == 0)
		*out_sz = 6;
	return (s_sz);
}

char	*ft_fl_m_s(char *s, t_flag flag, int nt, unsigned int *out_sz)
{
	char			*m;
	unsigned int	s_sz;

	s_sz = ft_get_ouszs(s, flag, nt, out_sz);
	m = malloc(*out_sz * sizeof(char) + 1);
	if (!m)
		return (0);
	m = ft_fl_init(m, *out_sz);
	if (flag.justify == 1)
		m = ft_fl_j_s(s, m, s_sz);
	else
		m = ft_fl_nj_s(s, m, s_sz, *out_sz);
	return (m);
}
