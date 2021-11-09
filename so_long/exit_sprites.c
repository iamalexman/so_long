/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:11:16 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:11:18 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_exit(t_data *data, void *exit, int h, int w)
{
	exit = "/Users/ebalgruu/Desktop/21/so_long/images/exit/gate_1.xpm";
	data->exit = mlx_xpm_file_to_image(data->mlx, exit, &h, &w);
}

static void	ft_exit_1(t_data *data, void *exit, int h, int w)
{
	exit = "/Users/ebalgruu/Desktop/21/so_long/images/exit/gate_2.xpm";
	data->exit = mlx_xpm_file_to_image(data->mlx, exit, &h, &w);
}

static void	ft_exit_2(t_data *data, void *exit, int h, int w)
{
	exit = "/Users/ebalgruu/Desktop/21/so_long/images/exit/gate_3.xpm";
	data->exit = mlx_xpm_file_to_image(data->mlx, exit, &h, &w);
}

static void	ft_exit_3(t_data *data, void *exit, int h, int w)
{
	exit = "/Users/ebalgruu/Desktop/21/so_long/images/exit/gate_4.xpm";
	data->exit = mlx_xpm_file_to_image(data->mlx, exit, &h, &w);
}

void	exit_animations(t_data *data)
{
	void	*exit;
	int		h;
	int		w;

	h = 0;
	w = 0;
	if (data->loop_counter > 0
		&& data->nbr_to_exit != data->collectibles)
		ft_exit(data, &exit, h, w);
	else if (data->loop_counter >= 15
		&& data->nbr_to_exit != data->collectibles)
		ft_exit_1(data, &exit, h, w);
	else if (data->loop_counter >= 30
		&& data->nbr_to_exit != data->collectibles)
		ft_exit_2(data, &exit, h, w);
	else if (data->loop_counter >= 45
		&& data->nbr_to_exit != data->collectibles)
	{
		ft_exit_3(data, &exit, h, w);
		data->loop_counter = 0;
	}
	else if (data->nbr_to_exit == data->collectibles)
		ft_exit_3(data, &exit, h, w);
}
