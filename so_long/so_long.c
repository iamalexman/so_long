/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:13:25 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:13:27 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lets_play(t_data *data)
{
	ft_mlx_init(data);
	mlx_loop_hook(data->mlx, ft_action, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	mlx_hook(data->mlx_win, 02, (1L << 2), ft_press_buttons, data);
	ft_make_images(data);
	mlx_loop(data->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc == 2)
	{
		if (ft_check(argv[1]) == -1)
			ft_error(0);
		ft_init_data_struct(&data);
		ft_map_reader(&data, argv[1]);
		lets_play(&data);
	}
	else
		ft_error(FILE_ERROR);
	exit(0);
}
