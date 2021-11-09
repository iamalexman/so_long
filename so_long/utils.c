/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:14:19 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:14:22 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	len_number(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_light(int n, char *str)
{
	int		len;
	int		i;

	len = len_number(n);
	i = len;
	if (n == 0)
	{
		str[0] = '0';
		str[i] = '\0';
	}
	len -= 1;
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[i] = '\0';
	return (str);
}

int	ft_check(char *argv)
{
	int	length;

	length = ft_strlen(argv);
	if ((argv[length - 4] != '.') || (argv[length - 3] != 'b')
		|| (argv[length - 2] != 'e') || (argv[length - 1] != 'r'))
	{
		write (1, "Invalid file\n", 13);
		return (-1);
	}
	return (0);
}

void	ft_validation(char **new_map, int size, t_data *data)
{
	static int	arr[3] = {0};
	int			i;
	int			j;

	i = 0;
	while (size)
	{
		j = 0;
		while (new_map[i][j])
		{
			if (new_map[i][j] == 'P')
				arr[0] += 1;
			else if (new_map[i][j] == 'C')
				arr[1] += 1;
			else if (new_map[i][j] == 'E')
				arr[2] += 1;
			if (new_map[i][j] == 'X')
				data->enemy_flag = 13;
			j++;
		}
		i++;
		size--;
	}
	if (arr[0] != 1 || arr[2] != 1 || arr[1] <= 0)
		ft_error(MAP_ERROR);
}

void	ft_get_map(char **old_map, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	while (i < data->height)
	{
		j = 0;
		data->map[i] = (char *)malloc(sizeof(char) * (data->width + 1));
		while (j < data->width)
		{
			data->map[i][j] = old_map[i][j];
			if (data->map[i][j] == 'C')
				data->collectibles++;
			j++;
		}
		data->map[i][j] = 0;
		i++;
	}
	data->map[i] = NULL;
}
