/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_ghost_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:11:27 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:11:29 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_big(t_data *data, void *enemy_big, int h, int w)
{
	enemy_big = "/Users/ebalgruu/Desktop/21/so_long/images/big/enemy_big.xpm";
	data->big_enemy = mlx_xpm_file_to_image(data->mlx, enemy_big, &h, &w);
}

void	ft_enemy_big2(t_data *data, void *enemy_big, int h, int w)
{
	enemy_big = "/Users/ebalgruu/Desktop/21/so_long/images/big/enemy_big2.xpm";
	data->big_enemy = mlx_xpm_file_to_image(data->mlx, enemy_big, &h, &w);
}

void	ft_enemy_big3(t_data *data, void *enemy_big, int h, int w)
{
	enemy_big = "/Users/ebalgruu/Desktop/21/so_long/images/big/enemy_big3.xpm";
	data->big_enemy = mlx_xpm_file_to_image(data->mlx, enemy_big, &h, &w);
}

void	ft_enemy_big4(t_data *data, void *enemy_big, int h, int w)
{
	enemy_big = "/Users/ebalgruu/Desktop/21/so_long/images/big/enemy_big4.xpm";
	data->big_enemy = mlx_xpm_file_to_image(data->mlx, enemy_big, &h, &w);
}

void	enemy_big_animations(t_data *data)
{
	void	*enemy;
	int		h;
	int		w;

	h = 0;
	w = 0;
	if (data->loop_counter >= 0 && data->loop_counter < 10)
		ft_enemy_big(data, &enemy, h, w);
	else if (data->loop_counter >= 10 && data->loop_counter < 20)
		ft_enemy_big2(data, &enemy, h, w);
	else if (data->loop_counter >= 20 && data->loop_counter < 30)
		ft_enemy_big3(data, &enemy, h, w);
	else if (data->loop_counter >= 30 && data->loop_counter < 40)
		ft_enemy_big4(data, &enemy, h, w);
}
