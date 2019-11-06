/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/03 19:39:39 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	void ft_show_map(int len, char *line)
**	Function to print user map
** **************************************************************************
*/

void			ft_show_map(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	printf("\n\tPRINT MAP  map_size=%d\n", map->size);
	while(i < map->size)
	{
		j = 0;
		printf("map[%d]	|", i);
		while(j < map->size)
		{
			printf("%d|", map->dig_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\tmap printed\n");
}

/*
** **************************************************************************
**	void ft_put_map_man()
**	Function to print map man
** **************************************************************************
*/

void				ft_put_map_man()
{
	ft_putstr("usage ./wolf3d ./maps/map.wolf3d:\n\
	\n\tMap width - [4-50]\n\
	Map height - [4-50]\n\
	w - wall block\n\
	o1 - objects[1-4]\n\
	1 - empty blocks with floor and ceiling[1-4]\n\
	p - player\n\
	\n");
}

/*
** **************************************************************************
**	static void ft_init_wall(char *line, t_map map)
**	Function to place walls everywhere
** **************************************************************************
*/

static void		ft_init_wall(int *ptr, int size)
{
	int			i;

	i = 0;
	while(i < size+1)
	{
		ptr[i] = 2;
		i++;
	}
}

/*
** **************************************************************************
**	static void ft_map_save(char *line, t_map map)
**	Function to save one line
** **************************************************************************
*/

int				ft_save_line(char *line, int *ptr, int size)
{
	int			i;

	i = -1;
	//ft_putstr("\nstartsave_line\n");
	ft_init_wall(ptr, size);
	while (++i < size)
	{
		if (!line)
			ptr[i] = 2;
		else
		{
			if (line[i] == '\0')
				break ;
			if (line[i] == 'w')
				ptr[i + 1] = 2;
			else if (line[i] == 'p')
				ptr[i + 1] = 0;
			else if (line[i] == '1')
				ptr[i + 1] = 0;
		}
	}
	
	return (1);
	//ft_putstr("\nstartsave_line\n");
}
