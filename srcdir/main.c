/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/01 18:42:27 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static void ft_read(char *source_f)
**	Function to get user map
** **************************************************************************
*/

static void					ft_read(int fd, t_w *w)
{
	int		res;
	int		i;

	w->map.size = 0;
	w->map.pl = 0;
	i = 0;
	res = 0;
	res = ft_map_chk(fd, w);
	if (!res)
	{
		ft_put_map_man();
		ft_putstr_fd("Map error.\n", 2);
		exit(1);
	}
	
}

/*
** **************************************************************************
**	static int ft_open(char *source_f)
**	Function to open map
** **************************************************************************
*/

static int					ft_open(char *source_f)
{
	int	fd;

	if ((fd = open(source_f, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Open error. Usage: sh ./run.sh\n", 2);
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

int					main(int argc, char **argv)
{
	clock_t			t;
	double			time_taken;
	t_w				new_w;
	int				fd;

	t = clock();
	if ((argc != 2) || (argv[1] == NULL))
	{
		ft_putstr_fd("Usage: sh ./run.sh\n", 2);
		exit(1);
	}
	fd = ft_open(argv[1]);
	ft_read(fd, &new_w);
	
	printf("\n|{after reading map we get mapsize=%d}|\n", new_w.map.size);
	ft_show_map(&new_w.map);
	ft_sdl_run(&new_w);
	//ft_ray(&new_w);
	t = clock() - t;
	time_taken = (double)t / CLOCKS_PER_SEC;
	printf("\ntime_taken = %f\n", time_taken);
	exit(0);
}

//read map
//check map W & H
//check symbols in map file
//printf map man
//save map in struct s_map
//save struct s_map into struct s_w
//build map
//place player
//catch user input
/*




*/