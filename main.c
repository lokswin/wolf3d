/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/18 16:37:59 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	int ft_wolf_read(char *source_f)
**	Function to get user map
** **************************************************************************
*/

int				ft_wolf_read(int fd, t_w *new_w)
{
	return (0);
}

/*
** **************************************************************************
**	static int ft_wolf_open(char *source_f)
**	Function to open map
** **************************************************************************
*/

static int		ft_wolf_open(char *source_f)
{
	int			fd;

	if ((fd = open(source_f, O_RDONLY)) < 0)
	{
		ft_putstr_fd("open error", 2);
		exit(1);
	}
	return (fd);
}


/*
** **************************************************************************
**	int main(int argc, char **argv)
**	Function to get user map
** **************************************************************************
*/

int				main(int argc, char **argv)
{
	clock_t		t;
	double		time_taken;
	t_w			new_w;
	int			fd;

	
	if (argc > 1)
	{
		ft_putstr("usage: sh ./run.sh\n");
		exit(1);
	}	
	fd = ft_wolf_open("map.wolf3d");
	ft_wolf_read(fd, &new_w);
	t = clock();
	foo();
	//read map
	//draw menu
	//build map
	//place player
	//catch user input
	t = clock() - t;
	time_taken = (double)t / CLOCKS_PER_SEC;
	printf("\ntime_taken = %f\n", time_taken);
	exit(0);
}
