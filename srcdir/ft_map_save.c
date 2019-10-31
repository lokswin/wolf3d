/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/31 20:08:45 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	void ft_show_map(int len, char *line)
**	Function to print user map
** **************************************************************************
*/

void		ft_show_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("\n\n\tPRINT MAP  map_size=%d\n", map->size);
	while(i < map->size)
	{
		j = 0;
		printf("|map[%d]", i);
		while(j < map->size)
		{
			printf("%d|", map->dig_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n\tmap printed\n");
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
**	static void ft_map_save(char *line, t_map map)
**	Function to save one line
** **************************************************************************
*/

void		ft_save_line(char *line, int *ptr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (line[i] == 'w')
			ptr[i] = 2;
		else if (line[i] == 'p')
			ptr[i] = 1;
		else if (line[i] == '1')
			ptr[i] = 0;
		else
			ptr[i] = 2;
		i++;
	}
	line += 0;
	ptr += 0;
}

/*
	while (line[i] != '\0')
	{
		if (line[i] == 'w')
			ptr[i] = 2;
		else if (line[i] == 'p')
			ptr[i] = 1;
		else if (line[i] == '1')
			ptr[i] = 0;
		else
			ptr[i] = 2;
		i++;
	}
	
*/