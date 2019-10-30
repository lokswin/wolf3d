/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 21:26:57 by drafe            ###   ########.fr       */
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
	printf("\n\n\tPRINT MAP\nmap_size=%d\n", map->size);
	while(i < map->size)
	{
		j = 0;
		printf("|map[%d]", i);
		while(j < map->size)
		{
			printf("%d|", map->dig_map[i][j]);
			//printf("map[%d][%d]=%d|", i, j, map->dig_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

/*
** **************************************************************************
**	static void ft_map_save(char *line, t_map map)
**	Function to save one line
** **************************************************************************
*/

void		ft_show_map(char *line, int *ptr)
{
	
}