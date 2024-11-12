/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:26:46 by loculy            #+#    #+#             */
/*   Updated: 2023/01/02 17:19:43 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	ft_lstclean(t_plist **lst)
{
	t_plist	*ll;
	t_plist	*tmp;

	if (lst == NULL)
		return ;
	ll = *lst;
	tmp = *lst;
	while (ll != NULL)
	{
		tmp = ll->next;
		if (ll->content != NULL)
			free(ll->content);
		free(ll);
		ll = tmp;
	}
	*lst = NULL;
}

void	ft_res_read(t_plist *act, char *res)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	if (!act)
		return ;
	while (act->next != NULL)
	{
		j = 0;
		s = act->content;
		while (j < act->size)
			res[i++] = s[j++];
		act = act->next;
	}
	j = 0;
	s = act->content;
	while (j < act->size)
		res[i++] = s[j++];
	res[i] = '\0';
}

char	*ft_result(int size, t_plist *out, int *error)
{
	char	*m;

	if (*error == 1)
		return (0);
	m = malloc(size + 1 * sizeof(char));
	if (!m)
		return (0);
	ft_res_read(out, m);
	return (m);
}
