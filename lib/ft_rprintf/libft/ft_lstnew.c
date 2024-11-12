/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:26:51 by loculy            #+#    #+#             */
/*   Updated: 2022/11/04 15:21:37 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*addlist;

	addlist = malloc(sizeof(t_list));
	if (!addlist)
		return (0);
	addlist->content = content;
	addlist->next = NULL;
	return (addlist);
}
