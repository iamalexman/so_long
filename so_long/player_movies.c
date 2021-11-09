/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:13:07 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:13:09 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data *data)
{
	if (data->map[data->x - 1][data->y] != '1'
		&& data->enemy_flag != 2)
	{
		if (data->map[data->x - 1][data->y] == '0'
			|| data->map[data->x - 1][data->y] == 'C')
		{
			data->map[data->x][data->y] = '0';
			if (data->map[data->x - 1][data->y] == 'C')
				data->nbr_to_exit += 1;
			data->map[data->x - 1][data->y] = 'P';
		}
		else if (data->map[data->x - 1][data->y] == 'E'
			&& data->nbr_to_exit == data->collectibles)
		{
			data->map[data->x][data->y] = '0';
			data->map[data->x - 1][data->y] = 'P';
			data->u_win = 1;
		}
		else if (data->map[data->x - 1][data->y] == 'X')
			ft_kill_message(data, 0, 0);
		data->actions += 1;
	}
}

void	ft_move_down(t_data *data)
{
	if (data->map[data->x + 1][data->y] != '1'
		&& data->enemy_flag != 2)
	{
		if (data->map[data->x + 1][data->y] == '0'
			|| data->map[data->x + 1][data->y] == 'C')
		{
			data->map[data->x][data->y] = '0';
			if (data->map[data->x + 1][data->y] == 'C')
				data->nbr_to_exit += 1;
			data->map[data->x + 1][data->y] = 'P';
		}
		else if (data->map[data->x + 1][data->y] == 'E'
			&& data->nbr_to_exit == data->collectibles)
		{
			data->map[data->x][data->y] = '0';
			data->map[data->x + 1][data->y] = 'P';
			data->u_win = 1;
		}
		else if (data->map[data->x + 1][data->y] == 'X')
			data->enemy_flag = 2;
		data->actions += 1;
	}
}

void	ft_move_left(t_data *data)
{
	if (data->map[data->x][data->y - 1] != '1'
		&& data->enemy_flag != 2)
	{
		if (data->map[data->x][data->y - 1] == '0'
			|| data->map[data->x][data->y - 1] == 'C')
		{
			data->map[data->x][data->y] = '0';
			if (data->map[data->x][data->y - 1] == 'C')
				data->nbr_to_exit += 1;
			data->map[data->x][data->y - 1] = 'P';
		}
		else if (data->map[data->x][data->y - 1] == 'E'
			&& data->nbr_to_exit == data->collectibles)
		{
			data->map[data->x][data->y] = '0';
			data->map[data->x][data->y - 1] = 'P';
			data->u_win = 1;
		}
		else if (data->map[data->x][data->y - 1] == 'X')
			data->enemy_flag = 2;
		data->actions += 1;
	}
}

void	ft_move_right(t_data *data)
{
	if (data->map[data->x][data->y + 1] != '1'
		&& data->enemy_flag != 2)
	{
		if ((data->map[data->x][data->y + 1] == '0'
			 || data->map[data->x][data->y + 1] == 'C'))
		{
			data->map[data->x][data->y] = '0';
			if (data->map[data->x][data->y + 1] == 'C')
				data->nbr_to_exit += 1;
			data->map[data->x][data->y + 1] = 'P';
		}
		else if (data->map[data->x][data->y + 1] == 'E'
			&& data->nbr_to_exit == data->collectibles)
		{
			data->map[data->x][data->y] = '0';
			data->map[data->x][data->y + 1] = 'P';
			data->u_win = 1;
		}
		else if (data->map[data->x][data->y + 1] == 'X')
			data->enemy_flag = 2;
		data->actions += 1;
	}
}
