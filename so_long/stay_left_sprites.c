/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stay_left_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:13:58 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:13:59 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move1_idle_left(t_data *data, void *player, int x, int y)
{
	int		h;
	int		w;

	player = "/Users/ebalgruu/Desktop/21/so_long/images/plr_idle/idle_l.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, player, &h, &w);
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->player, x, y);
}

static void	ft_move1_idle_left2(t_data *data, void *player, int x, int y)
{
	int		h;
	int		w;

	player = "/Users/ebalgruu/Desktop/21/so_long/images/plr_idle/idle_l2.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, player, &h, &w);
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->player, x, y);
}

static void	ft_move1_idle_left3(t_data *data, void *player, int x, int y)
{
	int		h;
	int		w;

	player = "/Users/ebalgruu/Desktop/21/so_long/images/plr_idle/idle_l3.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, player, &h, &w);
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->player, x, y);
}

static void	ft_move1_idle_left4(t_data *data, void *player, int x, int y)
{
	int		h;
	int		w;

	player = "/Users/ebalgruu/Desktop/21/so_long/images/plr_idle/idle_l4.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, player, &h, &w);
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->player, x, y);
}

void	player_idle_left_animations(t_data *data, float h, float w)
{
	void	*player;

	if (data->loop_counter >= 0 && data->loop_counter < 10)
		ft_move1_idle_left(data, &player, h, w);
	else if (data->loop_counter >= 10 && data->loop_counter < 20)
		ft_move1_idle_left2(data, &player, h, w);
	else if (data->loop_counter >= 20 && data->loop_counter < 30)
		ft_move1_idle_left3(data, &player, h, w);
	else if (data->loop_counter >= 30 && data->loop_counter < 40)
		ft_move1_idle_left4(data, &player, h, w);
	else if (data->loop_counter >= 40 && data->loop_counter < 50)
		ft_move1_idle_left4(data, &player, h, w);
	else if (data->loop_counter >= 50 && data->loop_counter < 60)
	{
		ft_move1_idle_left3(data, &player, h, w);
		data->loop_counter = 0;
	}
}
