/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:18:14 by loculy            #+#    #+#             */
/*   Updated: 2022/11/18 17:00:24 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_strflag_init(void)
{
	t_flag	flag;

	flag.value = 0;
	flag.before = 0;
	flag.after = 0;
	flag.justify = 0;
	flag.zero = 0;
	flag.precision = 0;
	flag.prefix = 0;
	flag.blank = 0;
	flag.positive = 0;
	flag.x = '0';
	return (flag);
}

t_flag	ft_flag_head(char *fmt, t_flag flag, int *i)
{
	while (fmt[*i] && ft_flag_start_checker(fmt[*i]))
	{
		if (fmt[*i] == '0')
			flag.zero = 1;
		if (fmt[*i] == '#')
			flag.prefix = 1;
		if (fmt[*i] == ' ')
			flag.blank = 1;
		if (fmt[*i] == '+')
			flag.positive = 1;
		if (fmt[*i] == '-')
			flag.justify = 1;
		*i = *i + 1;
	}
	return (flag);
}

t_flag	ft_flag_sub(char *fmt, t_flag flag, int *i)
{
	while (fmt[*i] && ft_isdigit(fmt[*i]))
	{
		flag.value = flag.value * 10 + (fmt[*i] - '0');
		*i = *i + 1;
	}
	if (fmt[*i] && fmt[*i] == '.')
	{
		flag.before = flag.value;
		flag.value = 0;
		flag.precision = 1;
		*i = *i + 1;
	}
	while (fmt[*i] && ft_isdigit(fmt[*i]))
	{
		flag.after = flag.after * 10 + (fmt[*i] - '0');
		*i = *i + 1;
	}
	return (flag);
}

int	ft_flag_format(va_list	arg, char ff, t_plist **out, t_mnf mnf)
{
	int	size;

	size = 0;
	if (ff == 'c')
		size += ft_fg_c(va_arg(arg, int), out, mnf.error, mnf.flag);
	else if (ff == 's')
		size += ft_fg_s(va_arg(arg, char *), out, mnf.error, mnf.flag);
	else if (ff == 'p')
		size += ft_fg_p(va_arg(arg, void *), out, mnf.error, mnf.flag);
	else if (ff == 'd')
		size += ft_fg_d(va_arg(arg, int), out, mnf.error, mnf.flag);
	else if (ff == 'i')
		size += ft_fg_d(va_arg(arg, int), out, mnf.error, mnf.flag);
	else if (ff == 'u')
		size += ft_fg_u(va_arg(arg, unsigned int), out, mnf.error, mnf.flag);
	else if (ff == 'x')
		size += ft_fg_x(va_arg(arg, unsigned int), out, mnf.error, mnf.flag);
	else if (ff == 'X')
		size += ft_fg_xx(va_arg(arg, unsigned int), out, mnf.error, mnf.flag);
	else if (ff == '%')
		size += ft_fg_c('%', out, mnf.error, mnf.flag);
	return (size);
}

int	ft_flag(va_list	arg, t_plist **out, char *fmt, t_mn mn)
{
	int		i;
	int		*ii;
	t_mnf	mnf;
	t_flag	flag;

	i = 0;
	ii = mn.i;
	flag = ft_strflag_init();
	flag = ft_flag_head(fmt, flag, &i);
	flag = ft_flag_sub(fmt, flag, &i);
	*ii = *ii + i;
	mnf.error = mn.error;
	mnf.flag = flag;
	return (ft_flag_format(arg, fmt[i], out, mnf));
}
