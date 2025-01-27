/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_toupper.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: elizohin <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/05/03 19:01:02 by elizohin		  #+#	#+#			 */
/*   Updated: 2023/05/03 19:01:02 by elizohin		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}

/*int main()
{
	unsigned char a = 'Q';

	printf("%d", ft_toupper(a));
	printf("%d", toupper(a));

}*/