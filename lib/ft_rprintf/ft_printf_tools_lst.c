/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:46:48 by loculy            #+#    #+#             */
/*   Updated: 2022/11/18 17:02:32 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_error_return(int *error, int erv)
{
	*error = erv;
	return (0);
}

int	ft_error_return_free(int *error, int erv, char *m)
{
	free(m);
	*error = erv;
	return (0);
}

t_plist	*ft_plstnew(void *content)
{
	t_plist			*addlist;

	addlist = malloc(sizeof(t_plist));
	if (!addlist)
		return (0);
	addlist->content = content;
	addlist->size = 0;
	addlist->next = NULL;
	return (addlist);
}

void	ft_plstadd_back(t_plist **lst, t_plist *new)
{
	t_plist	*act;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	act = *lst;
	while (act->next != NULL)
		act = act->next;
	act->next = new;
}
