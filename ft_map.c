/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/22 21:23:04 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static void ft_map_save(char *line, t_map map)
**	Function to save map
** **************************************************************************
*/

static void		ft_map_save(int len, char *line, t_map *map)
{
	line += 0;
	map->size = len;
}

/*
** **************************************************************************
**	int ft_map_chk(int fd, t_w *new_w)
**	Function to check user map
** **************************************************************************
*/

int					ft_map_chk(int fd, t_w *w)
{
	char	*line;
	int		res;
	int		i;

	i = 0;
	res = 1;
	while (i < MAX_MAP_H + 1)
	{
		res = ft_get_next_line(fd, &line);
		if (res == -1)
		{
			ft_putstr_fd("GNL error. ", 2);
			return (0);
		}
		else if (res == 0)
			break ;
		else if (i > MAX_MAP_H)
			return (0);
		if ((res = ft_strlen(line)) && (res > MAX_MAP_W))
			return (0);
		ft_map_save(res, line, &w->map);
		ft_strdel(&line);
		i++;
	}
	return(1);
}

/*
** **************************************************************************
**	void ft_put_map_man()
**	Function to print map man
** **************************************************************************
*/

void				ft_put_map_man()
{
	ft_putstr("usage map.wolf3d:\n\
	Max map height = 50 char\n\
	Max map width = 50 char\n\
	\n\
	\n\
	");
}
