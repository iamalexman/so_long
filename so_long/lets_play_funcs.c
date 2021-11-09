/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_play_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:12:26 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:12:28 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_color_to_image(t_data *data)
{
	int		color;

	color = data->color;
	color = 0xABCDEF;
	data->mlx_image = mlx_new_image(data->mlx, 240, 20);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->mlx_image, 12, 12);
	mlx_string_put(data->mlx, \
			data->mlx_win, 15, 11, 0xD0D0D0, "ACTIONS:");
	mlx_string_put(data->mlx, \
			data->mlx_win, 140, 11, 0xD0D0D0, "COINS:  /");
}

void	ft_drawing_map(t_data *data, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < *data->h)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->wall, x, y);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->exit, x + 5, y + 9);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->gift, x + 5, y + 9);
			j++;
			x += 40;
		}
		y += 40;
		i++;
		x = 0;
	}
}

void	ft_get_move_from_key(t_data *data)
{
	if (data->move == 66)
		ft_player_idle_move_draw(data, 0, 0);
	else if (data->move == 65)
		ft_player_idle_left_draw(data, 0, 0);
	if (data->move == D)
	{
		ft_move_right(data);
		data->move = 66;
	}
	else if (data->move == A)
	{
		ft_move_left(data);
		data->move = 65;
	}
	else if (data->move == W)
	{
		ft_move_up(data);
		data->move = 66;
	}
	else if (data->move == S)
	{
		ft_move_down(data);
		data->move = 66;
	}
}

int	ft_action(t_data *data)
{
	data->loop_counter++;
	mlx_clear_window(data->mlx, data->mlx_win);
	ft_drawing_map(data, 0, 0);
	if (data->enemy)
		ft_enemy_draw(data, 0, 0);
	ft_get_move_from_key(data);
	if (data->nbr_to_exit == data->collectibles)
		exit_animations(data);
	gifts_animations(data);
	enemy_big_animations(data);
	ft_drawing_tab_actions(data);
	if (data->nbr_to_exit == data->collectibles && data->u_win == 1)
		ft_win_message(data, 0, 0);
	if (data->enemy_flag == 2)
		ft_kill_message(data, 0, 0);
	return (0);
}
