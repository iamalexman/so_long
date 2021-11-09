/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stay_right_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:14:10 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:14:12 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move1_idle(t_data *data, void *player, int x, int y)
{
	int		h;
	int		w;

	player = "/Users/ebalgruu/Desktop/21/so_long/images/player_idle/idle-2.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, player, &h, &w);
	mlx_put_image_to_window(data->mlx, \
			data->mlx_win, data->player, x, y);
}

void	ft_move2_idle(t_data *data, void *player, int x, int y)
{
	int		h;
	int		w;

	player = "/Users/ebalgruu/Desktop/21/so_long/images/player_idle/idle-3.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, player, &h, &w);
	mlx_put_image_to_window(data->mlx, \
			data->mlx_win, data->player, x, y);
}

void	ft_move3_idle(t_data *data, void *player, int x, int y)
{
	int		h;
	int		w;

	player = "/Users/ebalgruu/Desktop/21/so_long/images/player_idle/idle-4.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, player, &h, &w);
	mlx_put_image_to_window(data->mlx, \
			data->mlx_win, data->player, x, y);
}

void	ft_move4_idle(t_data *data, void *player, int x, int y)
{
	int		h;
	int		w;

	player = "/Users/ebalgruu/Desktop/21/so_long/images/player_idle/idle-5.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, player, &h, &w);
	mlx_put_image_to_window(data->mlx, \
			data->mlx_win, data->player, x, y);
}

void	player_idle_animations(t_data *data, float h, float w)
{
	void	*player;

	if (data->loop_counter >= 0 && data->loop_counter < 10)
		ft_move1_idle(data, &player, h, w);
	else if (data->loop_counter >= 10 && data->loop_counter < 20)
		ft_move2_idle(data, &player, h, w);
	else if (data->loop_counter >= 20 && data->loop_counter < 30)
		ft_move3_idle(data, &player, h, w);
	else if (data->loop_counter >= 30 && data->loop_counter < 40)
		ft_move4_idle(data, &player, h, w);
	else if (data->loop_counter >= 40 && data->loop_counter < 50)
		ft_move3_idle(data, &player, h, w);
	else if (data->loop_counter >= 50 && data->loop_counter < 60)
	{
		ft_move2_idle(data, &player, h, w);
		data->loop_counter = 0;
	}
}
