/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/08 19:27:07 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static void ft_read(int fd, t_w *w)
**	Function to get read user map
** **************************************************************************
*/

static void			ft_read(int fd, t_w *w)
{
	int	res;
	int	i;

	w->map.size = 0;
	w->map.pl = 0;
	i = 0;
	res = 0;
	res = ft_map_chk(fd, w);
	if (!res)
	{
		ft_put_map_man();
		ft_putstr_fd("map error. usage: ./wolf3d path_to_map\n", 2);
		exit(1);
	}
}

/*
** **************************************************************************
**	static int ft_open(char *source_f)
**	Function to open map
** **************************************************************************
*/

static int			ft_open(char *source_f)
{
	int	fd;

	if ((fd = open(source_f, O_RDONLY)) < 0)
	{
		ft_putstr_fd("open error. usage: ./wolf3d path_to_map\n", 2);
		exit(1);
	}
	return (fd);
}

/*
** **************************************************************************
**	int main(int argc, char **argv)
**	Function to get program arguments
** **************************************************************************
*/

int					main(int argc, char **argv)
{
	t_w	new_w;
	int	fd;

	if ((argc != 2) || (argv[1] == NULL))
	{
		ft_putstr_fd("usage: ./wolf3d path_to_map\n", 2);
		exit(1);
	}
	fd = ft_open(argv[1]);
	ft_read(fd, &new_w);
	ft_engine(&new_w);
	exit(0);
}
