/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:11:42 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/09/10 18:11:45 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_read(int fd, char *buf, int *ret)
{
	return (*ret = (int) read(fd, buf, BUFFER_SIZE));
}

void	ft_freeshka(char **string)
{
	if (string && *string != NULL)
	{
		free(*string);
		*string = NULL;
	}
}

static int	ft_make_line(char **ost, char **line)
{
	char	*ptr_n;
	char	*tmp;

	ptr_n = ft_strchr(*ost, '\n');
	if (ptr_n)
	{
		*ptr_n = '\0';
		tmp = *ost;
		*line = ft_strdup(tmp);
		ptr_n++;
		*ost = ft_strdup(ptr_n);
		ft_freeshka(&tmp);
	}
	else
	{
		*line = ft_strdup(*ost);
		ft_freeshka(ost);
		return (0);
	}
	return (1);
}

static int	ft_out(char **ost, char **line, int ret)
{
	if (ret == 0)
	{
		if (ost)
			return (ft_make_line(ost, line));
		else
			*line = NULL;
		return (0);
	}
	else
		return (ft_make_line(ost, line));
}

int	get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*buf;
	char			*tmp;
	int				ret;

	ret = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((ft_read(fd, buf, &ret)) > 0)
	{
		buf[ret] = '\0';
		if (!ost)
			ost = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(ost, buf);
			ft_freeshka(&ost);
			ost = tmp;
			tmp = NULL;
		}
		if (ft_strchr(ost, '\n'))
			break ;
	}
	ft_freeshka(&buf);
	return (ft_out(&ost, line, ret));
}
