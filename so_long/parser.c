/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:12:58 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:13:00 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_images(t_data *data)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"/Users/ebalgruu/Desktop/21/so_long/images/wall.xpm", &h, &w);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"/Users/ebalgruu/Desktop/21/so_long/images/exit/gate_1.xpm",
			&h, &w);
	data->enemy = NULL;
	data->gift = mlx_xpm_file_to_image(data->mlx,
			"/Users/ebalgruu/Desktop/21/so_long/images/black.xpm", &h, &w);
	data->grave = mlx_xpm_file_to_image(data->mlx,
			"/Users/ebalgruu/Desktop/21/so_long/images/grave.xpm", &h, &w);
}

void	ft_check_map(char **map, int width, int height)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	while (map[i] && i < height)
	{
		j = 0;
		while (map[i][j] && j < width)
		{
			if (map[0][j] != '1' || map[i][0] != '1'
				|| map[i][width] != '1' || map[height][j] != '1')
				ft_error(MAP_ERROR);
			if (map[i][j] == '1'
				|| map[i][j] == '0' || map[i][j] == 'P'
				|| map[i][j] == 'E' || map[i][j] == 'C')
				j++;
			else
				ft_error(MAP_ERROR);
		}
		i++;
		len = ft_strlen(map[i]);
		if (width != len - 1 && len != 0)
			ft_error(MAP_ERROR);
	}
}

void	ft_map_reader(t_data *data, char *argv)
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
	fd = open(argv, O_RDONLY);
	while (out > 0)
	{
		out = get_next_line(fd, &map[i]);
		if (out < 0)
			ft_error(READ_ERROR);
		i++;
	}
	map[i] = NULL;
	ft_validation(map, i, data);
	ft_check_map(map, data->width - 1, data->height - 1);
	ft_get_map(map, data);
	free_map(map);
}
