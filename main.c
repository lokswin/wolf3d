/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/20 17:43:54 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	int ft_wolf_read(char *source_f)
**	Function to get user map
** **************************************************************************
*/

int							ft_wolf_read(int fd, t_w *new_w)
{
	fd += 0;
	new_w += 0;
	return (0);
}

/*
** **************************************************************************
**	static int ft_wolf_open(char *source_f)
**	Function to open map
** **************************************************************************
*/

static int					ft_wolf_open(char *source_f)
{
	int						fd;

	if ((fd = open(source_f, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Open error.", 2);
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

int							main(int argc, char **argv)
{
	clock_t					t;
	double					time_taken;
	t_w						new_w;
	int						fd;
	mat4					matrix;
	vec4					vec;

	t = clock();
	//ft_run_vk();
	ft_run_glfw();
	glm_mat4_mulv(matrix, vec, vec);
	if ((argc > 1) && (argv[1] != NULL))
	{
		ft_putstr_fd("Usage: sh ./run.sh\n", 2);
		exit(1);
	}
	fd = ft_wolf_open("map.wolf3d");
	ft_wolf_read(fd, &new_w);
	t = clock() - t;
	time_taken = (double)t / CLOCKS_PER_SEC;
	printf("\ntime_taken = %f\n", time_taken);
	exit(0);
}

//read map
//draw menu
//build map
//place player
//catch user input