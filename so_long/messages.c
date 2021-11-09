/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:12:35 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:12:37 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_drawing_tab_actions(t_data *data)
{
	char	str[BUFFER_SIZE];

	ft_put_color_to_image(data);
	mlx_string_put(data->mlx, data->mlx_win, 98, 11, 0xD0D0D0, \
				   ft_itoa_light(data->actions, str));
	mlx_string_put(data->mlx, data->mlx_win, 201, 11, 0xD0D0D0, \
				   ft_itoa_light(data->nbr_to_exit, str));
	mlx_string_put(data->mlx, data->mlx_win, 230, 11, 0xD0D0D0, \
				   ft_itoa_light(data->collectibles, str));
}

static void	ft_coins(t_data *data, int h, int w)
{
	while (h < 3000)
	{
		mlx_put_image_to_window(data->mlx, \
			data->mlx_win, data->gift, h, w);
		h += 30;
	}
}

int	ft_win_message(t_data *data, int x, int y)
{
	x = *(data)->h;
	y = *(data)->w;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_string_put(data->mlx, data->mlx_win, \
				   y * 15, x * 19, 0xD0D0D0, "!!!YOU WON!!!");
	ft_coins(data, 0, x * 5);
	ft_coins(data, 0, x * 28);
	return (0);
}

int	ft_kill_message(t_data *data, int x, int y)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	x = *data->h;
	y = *data->w;
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_xpm_file_to_image(data->mlx, \
		"/Users/ebalgruu/Desktop/21/so_long/images/grave.xpm", &h, &w);
	mlx_put_image_to_window(data->mlx, \
		data->mlx_win, data->grave, y * 10, y * 3);
	mlx_put_image_to_window(data->mlx, \
		data->mlx_win, data->big_enemy, y * 25, y * 3);
	mlx_string_put(data->mlx, \
		data->mlx_win, y * 18, y * 5, 0xD0D0D0, "!!!R.I.P!!!");
	return (0);
}
