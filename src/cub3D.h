/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:33:48 by almichel          #+#    #+#             */
/*   Updated: 2024/11/12 17:57:32 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

# include "MLX42/MLX42.h"
# include "../lib/ft_rprintf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft42/libft.h"


typedef struct s_data
{
	void	*mlx;
	void	*mlx_wind;
	char	**file;
	char	**map;
	char	**tab;
	char	*_no;
	char	*_so;
	char	*_we;
	char	*_ea;
	char	*_do;
	int		readed;
}			t_data;

/*--------PARSING--------*/
int	    ft_errormap(char *str);
int	    ft_check_cub(char *argv);
char	**ft_read_and_stock(char *argv, t_data *data);
char	**ft_stock(char **dest, char *argv, int fd, int size);
char	*ft_check_retour(char *dest);
void 	stock_elem(t_data *data);
void 	stock_elem2(char **file, char **tab, int i, int j);

#endif