/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:33:48 by almichel          #+#    #+#             */
/*   Updated: 2024/11/19 17:39:30 by almichel         ###   ########.fr       */
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

typedef struct s_player
{
	int		y;
	int		x;
	char	pos;
}			t_player;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_wind;
	char	**file;
	char	**map;
	char	**tab;
	char	**stock_c;
	char	**stock_f;
	char	*_no;
	char	*_so;
	char	*_we;
	char	*_ea;
	char	*_do;
	char	*_c;
	char	*_f;
	int		readed;
	t_player player;
}			t_data;

/*--------PARSING--------*/
int	    ft_errormap(char *str);
int	    ft_check_cub(char *argv);
char	**ft_read_and_stock(char *argv, t_data *data);
char	**ft_stock(char **dest, char *argv, int fd, int size);
char	*ft_check_retour(char *dest);
void 	stock_data(t_data *data);
void 	stock_texts(char **file, char **tab, int i, int j);
void 	stock_colors(char **file, char **tab, int i, int j);
void    check_color(char *color);
void 	check_255_color(char **tab);
void 	copy_map(char **file, int i, int j, char ***map);
int 	check_map(char **map, t_data *data);
int 	check_first_last_wall(char **map);
int 	del_space_map(char *str);
int 	check_spaces(char **map, int i, int j);

/*--------UTILS--------*/
int    	ft_count(char *str);
char    **ft_strcpy_modif(char **tab, char *str);
char    **ft_split_modif(char *str);
int 	is_a_char_map(char c);
int 	all_data_are_stocked(t_data *data);
char	**ft_doublefree(char **tab, int k);

#endif