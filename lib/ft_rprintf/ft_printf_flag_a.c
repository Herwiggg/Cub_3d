/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:27:36 by loculy            #+#    #+#             */
/*   Updated: 2022/11/18 16:22:03 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fg_c(char c, t_plist **out, int *error, t_flag flag)
{
	unsigned int	out_sz;
	t_plist			*new;
	char			f[2];
	char			*m;

	f[0] = c;
	f[1] = '\0';
	out_sz = 0;
	m = ft_fl_m_s(f, flag, 1, &out_sz);
	if (m == 0)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
	{
		free(m);
		return (ft_error_return(error, 1));
	}
	new->size = out_sz;
	ft_plstadd_back(out, new);
	return (out_sz);
}

int	ft_fg_s(char *s, t_plist **out, int *error, t_flag flag)
{
	unsigned int	out_sz;
	t_plist			*new;
	char			*m;

	out_sz = 0;
	if (s == NULL)
		m = ft_fl_m_s("(null)", flag, 2, &out_sz);
	else
		m = ft_fl_m_s(s, flag, 0, &out_sz);
	if (m == NULL)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
	{
		free(m);
		return (ft_error_return(error, 1));
	}
	new->size = out_sz;
	ft_plstadd_back(out, new);
	return (out_sz);
}

int	ft_fg_p(void *p, t_plist **out, int *error, t_flag flag)
{
	unsigned int	out_sz;
	unsigned long	n;
	char			*m;
	char			*f;
	t_plist			*new;

	out_sz = 0;
	n = (unsigned long)p;
	f = ft_phex(n);
	if (f == NULL)
		return (ft_error_return(error, 1));
	m = ft_fl_m_s(f, flag, 0, &out_sz);
	free(f);
	if (m == NULL)
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

int	ft_fg_d(int a, t_plist **out, int *error, t_flag flag)
{
	unsigned int	out_sz;
	t_plist			*new;
	char			*m;
	char			*f;

	out_sz = 0;
	flag.x = '0';
	f = ft_itoa(a);
	if (f == NULL)
		return (ft_error_return(error, 1));
	m = ft_fl_m_d(f, flag, &out_sz);
	free(f);
	if (m == NULL)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
	{
		free(m);
		return (ft_error_return(error, 1));
	}
	new->size = out_sz;
	ft_plstadd_back(out, new);
	return (out_sz);
}

int	ft_fg_u(unsigned int a, t_plist **out, int *error, t_flag flag)
{
	unsigned int	out_sz;
	t_plist			*new;
	char			*m;
	char			*f;

	out_sz = 0;
	flag.x = '0';
	f = ft_pitoa(a);
	if (f == NULL)
		return (ft_error_return(error, 1));
	m = ft_fl_m_d(f, flag, &out_sz);
	free(f);
	if (m == NULL)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
	{
		free(m);
		return (ft_error_return(error, 1));
	}
	new->size = out_sz;
	ft_plstadd_back(out, new);
	return (out_sz);
}
