/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:31:19 by loculy            #+#    #+#             */
/*   Updated: 2022/11/07 14:52:39 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ll;
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	ll = *lst;
	tmp = *lst;
	while (ll != NULL)
	{
		tmp = ll->next;
		if (ll->content != NULL)
			del(ll->content);
		free(ll);
		ll = tmp;
	}
	*lst = NULL;
}
