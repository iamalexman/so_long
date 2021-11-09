/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:12:15 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:12:17 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	ft_send_key(int key, t_data *data)
{
	if (key == W && data->u_win == 0)
		data->move = W;
	else if (key == S && data->u_win == 0)
		data->move = S;
	else if (key == A && data->u_win == 0)
		data->move = A;
	else if (key == D && data->u_win == 0)
		data->move = D;
	else if (key == ESC)
		ft_close(data);
}

int	ft_press_buttons(int key, t_data *data)
{
	ft_send_key(key, data);
	if (data->enemy_flag != 2)
		printf("%d steps\n", data->actions);
	if (data->enemy)
	{
		if (data->enemy_flag == 0)
			ft_enemy_walk(data);
		else if (data->enemy_flag == 1)
			ft_enemy_walk_2(data);
	}
	return (key);
}
