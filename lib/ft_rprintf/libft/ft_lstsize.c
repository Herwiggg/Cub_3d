/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:10:34 by loculy            #+#    #+#             */
/*   Updated: 2022/11/04 15:21:39 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*act;
	int		size;

	if (!lst)
		return (0);
	size = 1;
	act = lst;
	while (act->next != NULL)
	{
		size++;
		act = act->next;
	}
	return (size);
}
