/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:33:59 by almichel          #+#    #+#             */
/*   Updated: 2024/11/18 18:58:47 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int ac, char **av)
{
    t_data	data;

	ft_bzero(&data, sizeof(t_data));
    if (ac != 2)
        ft_errormap("Wrong number of args\n");
    if (ft_check_cub(av[1]) == -1)
        ft_errormap("File is not a .cub\n");
    data.file = ft_read_and_stock(av[1], &data);
    if (data.file == NULL)
		return (-1);
    stock_data(&data);
//    printf("%s\n", data._so);
 //   printf("%s\n", data._so);
  //  printf("%s\n", data._c);
    // int i = 0;
    // while(data.stock_c[i])
    // {
    //     printf("%s\n", data.stock_c[i]);
    //     i++;
    // }
    return (0);
}

