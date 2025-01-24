/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:21:04 by almichel          #+#    #+#             */
/*   Updated: 2025/01/24 23:53:07 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// retravailler ca
void	theend(t_info *info, int x)
{
	info->y = info->drawstart;
	while (info->y < info->drawend)
	{
		info->texy = (int)info->texpos & (TEXHEIGHT - 1);
		info->texpos += info->step;
		wall_color(info);
		if (info->side == 1)
			info->color = (info->color >> 1) & 8355711;
		info->buf[info->y][x] = info->color;
		info->re_buf = 1;
		info->y++;
	}
}

void	destroy_win_disp(t_info *info)
{
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx)
		mlx_destroy_display(info->mlx);
	free(info->mlx);
}

int	game(t_info *info)
{
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		return (printf("Error\nmauvaise initialisation\n"), 0);
	info->re_buf = 0;
	direction_player_n_s(info, info->player);
	if (smallparsing(info) == -1)
		return (printf("Error\n parsing error\n"), free_texture(info), 0);
	load_texture(info);
	info->movespeed = 0.009;
	info->rotspeed = 0.007;
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx");
	if (info->win == NULL)
		return (printf("Error\nmauvaise initialisation\n"), 0);
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
			&info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, 2, 1L << 0, &key_press, info);
	mlx_hook(info->win, 3, 1L << 1, &key_release, info);
	mlx_hook(info->win, 17, 0, &close_click, info);
	mlx_loop(info->mlx);
	mlx_destroy_image(info->mlx, info->img.img);
	destroy_win_disp(info);
	return (free_texture(info), 0);
}

int	parsing(char *file, t_jeu *jeu)
{
	copy_file(file, jeu);
	copy_map_value(file, jeu);
	check_map_value(jeu);
	copy_game_map(jeu);
	parsing_map(jeu);
	check_position(jeu);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_jeu	jeu = {0};
	static t_info	info = {0};
	t_data			data;

	ft_bzero(&data, sizeof(t_data));
	if (argc == 2)
	{
		if (ft_check_cub(argv[1]) == -1)
			ft_errormap("File is not a .cub\n");
		data.file = ft_read_and_stock(argv[1], &data);
		stock_data(&data);
		check_map(data.map);
		jeu.floor_colors = copy_double_tab(data.stock_f, jeu.floor_colors);
		jeu.ceiling_colors = copy_double_tab(data.stock_c, jeu.ceiling_colors);
		free_check(&data);
		if (parsing(argv[1], &jeu))
			return (1);
		fusion(&jeu, &info);
		if (game(&info) != 0)
			return (0);
		free_exit(&jeu);
	}
	else
		ft_errormap("Wrong Args !\n");
	return (0);
}

