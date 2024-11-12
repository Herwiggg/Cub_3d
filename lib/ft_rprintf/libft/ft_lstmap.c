/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:44:56 by loculy            #+#    #+#             */
/*   Updated: 2022/11/09 14:06:53 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*new;
	void	*tmp;

	out = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new = ft_lstnew(tmp);
		if (new == NULL)
		{
			ft_lstclear(&out, del);
			del(tmp);
			return (0);
		}
		ft_lstadd_back(&out, new);
		lst = lst->next;
	}
	return (out);
}
