/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:10:58 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:11:01 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_gifts(t_data *data, void *gift, int h, int w)
{
	gift = "/Users/ebalgruu/Desktop/21/so_long/images/gift/gift.xpm";
	data->gift = mlx_xpm_file_to_image(data->mlx, gift, &h, &w);
}

static void	ft_gifts2(t_data *data, void *gift, int h, int w)
{
	gift = "/Users/ebalgruu/Desktop/21/so_long/images/gift/gift2.xpm";
	data->gift = mlx_xpm_file_to_image(data->mlx, gift, &h, &w);
}

static void	ft_gifts3(t_data *data, void *gift, int h, int w)
{
	gift = "/Users/ebalgruu/Desktop/21/so_long/images/gift/gift3.xpm";
	data->gift = mlx_xpm_file_to_image(data->mlx, gift, &h, &w);
}

static void	ft_gifts4(t_data *data, void *gift, int h, int w)
{
	gift = "/Users/ebalgruu/Desktop/21/so_long/images/gift/gift4.xpm";
	data->gift = mlx_xpm_file_to_image(data->mlx, gift, &h, &w);
}

void	gifts_animations(t_data *data)
{
	void	*friends;
	int		h;
	int		w;

	h = 0;
	w = 0;
	if (data->loop_counter == 0)
		ft_gifts(data, &friends, h, w);
	else if (data->loop_counter == 10)
		ft_gifts2(data, &friends, h, w);
	else if (data->loop_counter == 20)
		ft_gifts3(data, &friends, h, w);
	else if (data->loop_counter == 30)
		ft_gifts4(data, &friends, h, w);
	else if (data->loop_counter == 40)
		ft_gifts3(data, &friends, h, w);
	else if (data->loop_counter == 50)
		ft_gifts2(data, &friends, h, w);
}
