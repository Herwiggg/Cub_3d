/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstadd_back.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: elizohin <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/06 15:29:10 by elizohin		  #+#	#+#			 */
/*   Updated: 2023/05/06 15:29:10 by elizohin		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

/*
- on fait pointer next du dernier element sur new
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}
