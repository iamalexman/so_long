/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movies.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:12:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:12:47 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_walk(t_data *data)
{
	while (data->map[data->enemy_x - 1][data->enemy_y] == '0')
	{
		data->map[data->enemy_x][data->enemy_y] = '0';
		data->map[data->enemy_x - 1][data->enemy_y] = 'X';
	}
	if (data->map[data->enemy_x - 1][data->enemy_y] == '1')
		data->enemy_flag = 1;
	else if (data->map[data->enemy_x - 1][data->enemy_y] == 'P')
		data->enemy_flag = 2;
}

void	ft_enemy_walk_2(t_data *data)
{
	while (data->map[data->enemy_x + 1][data->enemy_y] == '0')
	{
		data->map[data->enemy_x][data->enemy_y] = '0';
		data->map[data->enemy_x + 1][data->enemy_y] = 'X';
	}
	if (data->map[data->enemy_x + 1][data->enemy_y] == '1')
		data->enemy_flag = 0;
	else if (data->map[data->enemy_x + 1][data->enemy_y] == 'P')
		data->enemy_flag = 2;
}

void	ft_enemy_draw(t_data *data, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < *data->h)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'X')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->enemy, x + 5, y + 10);
				enemy_animations(data);
				data->enemy_x = i;
				data->enemy_y = j;
			}
			j++;
			x += 40;
		}
		y += 40;
		i++;
		x = 0;
	}
}

void	ft_player_idle_left_draw(t_data *data, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->x = i;
				data->y = j;
				player_idle_left_animations(data, x + 3, y + 9);
			}
			j++;
			x += 40;
		}
		y += 40;
		i++;
		x = 0;
	}
}

void	ft_player_idle_move_draw(t_data *data, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < *data->h)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->x = i;
				data->y = j;
				player_idle_animations(data, x + 3, y + 8);
			}
			j++;
			x += 40;
		}
		y += 40;
		i++;
		x = 0;
	}
}
