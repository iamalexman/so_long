/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:11:08 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:11:10 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_enemy(t_data *data, void *enemy, int h, int w)
{
	enemy = "/Users/ebalgruu/Desktop/21/so_long/images/enemy/ghost.xpm";
	data->enemy = mlx_xpm_file_to_image(data->mlx, enemy, &h, &w);
}

static void	ft_enemy2(t_data *data, void *enemy, int h, int w)
{
	enemy = "/Users/ebalgruu/Desktop/21/so_long/images/enemy/ghost2.xpm";
	data->enemy = mlx_xpm_file_to_image(data->mlx, enemy, &h, &w);
}

static void	ft_enemy3(t_data *data, void *enemy, int h, int w)
{
	enemy = "/Users/ebalgruu/Desktop/21/so_long/images/enemy/ghost3.xpm";
	data->enemy = mlx_xpm_file_to_image(data->mlx, enemy, &h, &w);
}

static void	ft_enemy4(t_data *data, void *enemy, int h, int w)
{
	enemy = "/Users/ebalgruu/Desktop/21/so_long/images/enemy/ghost4.xpm";
	data->enemy = mlx_xpm_file_to_image(data->mlx, enemy, &h, &w);
}

void	enemy_animations(t_data *data)
{
	void	*enemy;
	int		h;
	int		w;

	h = 0;
	w = 0;
	if (data->loop_counter >= 0 && data->loop_counter < 10)
		ft_enemy(data, &enemy, h, w);
	else if (data->loop_counter >= 10 && data->loop_counter < 20)
		ft_enemy2(data, &enemy, h, w);
	else if (data->loop_counter >= 20 && data->loop_counter < 30)
		ft_enemy3(data, &enemy, h, w);
	else if (data->loop_counter >= 30 && data->loop_counter < 40)
		ft_enemy4(data, &enemy, h, w);
	else if (data->loop_counter >= 40 && data->loop_counter < 50)
		ft_enemy4(data, &enemy, h, w);
	else if (data->loop_counter >= 50 && data->loop_counter < 60)
	{
		ft_enemy(data, &enemy, h, w);
		data->loop_counter = 0;
	}
}
