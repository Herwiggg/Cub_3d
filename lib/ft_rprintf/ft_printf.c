/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:43:03 by loculy            #+#    #+#             */
/*   Updated: 2023/01/02 17:12:45 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_parse_format(va_list	arg, char *ff, t_plist **out, t_mn mn)
{
	int	size;

	size = 0;
	if (ff[0] == 'c')
		size += ft_w_c(va_arg(arg, int), out, mn.error);
	else if (ff[0] == 's')
		size += ft_w_s(va_arg(arg, char *), out, mn.error);
	else if (ff[0] == 'p')
		size += ft_w_p(va_arg(arg, void *), out, mn.error);
	else if (ff[0] == 'd')
		size += ft_w_d(va_arg(arg, int), out, mn.error);
	else if (ff[0] == 'i')
		size += ft_w_d(va_arg(arg, int), out, mn.error);
	else if (ff[0] == 'u')
		size += ft_w_u(va_arg(arg, unsigned int), out, mn.error);
	else if (ff[0] == 'x')
		size += ft_w_x(va_arg(arg, unsigned int), out, mn.error);
	else if (ff[0] == 'X')
		size += ft_w_xx(va_arg(arg, unsigned int), out, mn.error);
	else if (ff[0] == '%')
		size += ft_w_c('%', out, mn.error);
	else if (ft_flag_valider(ff))
		size += ft_flag(arg, out, ff, mn);
	return (size);
}

unsigned int	ft_printf_loop(va_list arg, const char *fmt, t_plist **out,
	int *error)
{
	t_mn	mn;
	int		size;
	int		i;

	i = 0;
	size = 0;
	mn.error = error;
	mn.i = &i;
	while (fmt[i] && *error == 0)
	{
		if (fmt[i] == '%')
			size += ft_parse_format(arg, (char *)&fmt[++i], out, mn);
		else
			size += ft_w_c(fmt[i], out, error);
		i++;
	}
	return (size);
}

char	*ft_rprintf(const char *fmt, ...)
{
	va_list			arg;
	t_plist			*out;
	unsigned int	size;
	char			*res;
	int				error;

	size = 0;
	out = 0;
	error = 0;
	if (fmt[0] == '\0')
		return (0);
	va_start (arg, fmt);
	size = ft_printf_loop(arg, fmt, &out, &error);
	va_end (arg);
	res = ft_result(size, out, &error);
	ft_lstclean(&out);
	return (res);
}
