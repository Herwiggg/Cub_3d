/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_argu_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seya <seya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:05:13 by loculy            #+#    #+#             */
/*   Updated: 2023/06/24 00:03:11 by seya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_w_c(char c, t_plist **out, int *error)
{
	t_plist	*new;
	char	m[2];
	char	*f;

	m[0] = c ;
	m[1] = '\0';
	f = ft_strdup(m);
	if (f == 0)
		return (ft_error_return(error, 1));
	new = ft_plstnew(f);
	if (new == NULL)
	{
		free(f);
		return (ft_error_return(error, 1));
	}
	new->size = 1;
	ft_plstadd_back(out, new);
	return (1);
}

int	ft_w_s(char *s, t_plist **out, int *error)
{
	t_plist	*new;
	//int		i;
	char	*m;

	//i = 0;
	if (s == NULL)
		m = ft_strdup("(null)");
	else
		m = ft_strdup(s);
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

int	ft_w_p(void *p, t_plist **out, int *error)
{
	unsigned long	n;
	char			*m;
	t_plist			*new;

	n = (unsigned long)p;
	m = ft_phex(n);
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

int	ft_w_d(int a, t_plist **out, int *error)
{
	t_plist	*new;
	int		neg;
	char	*m;

	neg = 0;
	m = ft_itoa(a);
	if (m == NULL)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
	{
		free(m);
		return (ft_error_return(error, 1));
	}
	if (a < 0)
	{
		a = -a;
		neg = 1;
	}
	new->size = ft_pitoa_size(a) + neg;
	ft_plstadd_back(out, new);
	return (ft_pitoa_size(a) + neg);
}

int	ft_w_u(unsigned int a, t_plist **out, int *error)
{
	t_plist	*new;
	char	*m;

	m = ft_pitoa(a);
	if (m == NULL)
		return (ft_error_return(error, 1));
	new = ft_plstnew(m);
	if (new == NULL)
	{
		free(m);
		return (ft_error_return(error, 1));
	}
	new->size = ft_pitoa_size(a);
	ft_plstadd_back(out, new);
	return (ft_pitoa_size(a));
}
