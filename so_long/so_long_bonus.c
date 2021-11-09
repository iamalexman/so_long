/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:13:36 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:13:38 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_bonus_map(char **map, int w, int h)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	while (map[i] && i < h)
	{
		j = 0;
		while (map[i][j] && j < w)
		{
			if (map[0][j] != '1' || map[i][0] != '1'
				|| map[i][w] != '1' || map[h][j] != '1')
				ft_error(MAP_ERROR);
			if (map[i][j] == '1'
				|| map[i][j] == '0' || map[i][j] == 'P'
				|| map[i][j] == 'E' || map[i][j] == 'C' || map[i][j] == 'X')
				j++;
			else
				ft_error(MAP_ERROR);
		}
		i++;
		len = ft_strlen(map[i]);
		if (w != len - 1 && len != 0)
			ft_error(MAP_ERROR);
	}
}

void	ft_bonus_map_reader(t_data *data, char *argv)
{
	char		**map;
	int			out;
	int			fd;
	int			i;

	i = 0;
	out = 1;
	ft_get_map_size(data, out, argv);
	map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!map)
		ft_error (MALLOC_ERROR);
	fd = open (argv, O_RDONLY);
	while (out > 0)
	{
		out = get_next_line(fd, &map[i]);
		if (out < 0)
			ft_error(READ_ERROR);
		i++;
	}
	map[i] = NULL;
	ft_validation(map, i, data);
	ft_check_bonus_map(map, data->width - 1, data->height - 1);
	ft_get_map(map, data);
	free_map(map);
}

void	ft_make_bonus_images(t_data *data)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"/Users/ebalgruu/Desktop/so_long/so_long/images/wall.xpm", &h, &w);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"/Users/ebalgruu/Desktop/so_long/so_long/images/exit/gate_1.xpm",
			&h, &w);
	if (data->enemy_flag == 13)
	{
		data->enemy = mlx_xpm_file_to_image(data->mlx,
				"/Users/ebalgruu/Desktop/git/images/enemy/ghost.xpm", &h, &w);
		data->enemy_flag = 0;
	}
	else
		data->enemy = NULL;
	data->gift = mlx_xpm_file_to_image(data->mlx,
			"/Users/ebalgruu/Desktop/so_long/so_long/images/black.xpm", &h, &w);
	data->grave = mlx_xpm_file_to_image(data->mlx,
			"/Users/ebalgruu/Desktop/so_long/so_long/images/grave.xpm", &h, &w);
}

int	lets_play_bonus(t_data *data)
{
	ft_mlx_init(data);
	mlx_loop_hook(data->mlx, ft_action, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_hook(data->mlx_win, 02, (1L << 2), ft_press_buttons, data);
	ft_make_bonus_images(data);
	ft_drawing_tab_actions(data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc == 2)
	{
		if (ft_check(argv[1]) == -1)
			ft_error(0);
		ft_init_data_struct(&data);
		ft_bonus_map_reader(&data, argv[1]);
		lets_play_bonus(&data);
	}
	else
		ft_error(FILE_ERROR);
	exit(0);
}
