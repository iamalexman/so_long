/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:12:03 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:12:05 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map_size(t_data *data, int out, char *argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (out > 0)
	{
		out = get_next_line(fd, &line);
		if (out < 0)
			ft_error(READ_ERROR);
		if (i == 0)
			data->width = ft_strlen(line);
		free(line);
		i++;
	}
	line = NULL;
	data->height = i;
	close(fd);
}

void	ft_error(int data)
{
	write (1, "Error\n", 6);
	if (data == 100)
		write(1, "FILE_ERROR\n", 11);
	else if (data == 101)
		write (1, "MAP_ERROR\n", 10);
	else if (data == 102)
		write (1, "MALLOC_ERROR\n", 13);
	else if (data == 103)
		write (1, "READ_ERROR\n", 11);
	else
		write (1, "COMMON_ERROR\n", 13);
	exit(0);
}

void	ft_init_data_struct(t_data *data)
{
	data->mlx_image = 0;
	data->mlx_win = 0;
	data->grave = 0;
	data->mlx = 0;
	data->x = 0;
	data->y = 0;
	data->w = 0;
	data->h = 0;
	data->map = 0;
	data->width = 0;
	data->height = 0;
	data->color = 0;
	data->u_win = 0;
	data->move = 66;
	data->enemy = 0;
	data->actions = 0;
	data->enemy_x = 0;
	data->enemy_y = 0;
	data->big_enemy = 0;
	data->enemy_flag = 0;
	data->nbr_to_exit = 0;
	data->loop_counter = 0;
	data->collectibles = 0;
}

void	ft_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->width * 40, \
			data->height * 40, "SO_LONG");
	data->h = &data->height;
	data->w = &data->width;
}

void	free_map(char **data)
{
	int		i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}
