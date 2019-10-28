/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/23 16:22:09 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
/*
** **************************************************************************
**	static void ft_map_chk_p2(int len, char *line)
**	Second function to check user map symbols
** **************************************************************************
*/

static int		ft_map_chk_exp(int len, char *line)
{
	int			i;

	i = 0;
	line += 0;
	if ((len > MAX_MAP_W) || (len < MIN_MAP_W))
			return (0);
	while (i < len)
	{
		if (line[i] != 'w')
			return (0);
		i++;
	}
	return (1);
}

/*
** **************************************************************************
**	static void ft_map_save(char *line, t_map map)
**	Function to save map
** **************************************************************************
*/

static int		ft_map_save(int len, char *line, t_map *map)
{
	if (!ft_map_chk_exp(len, line))
		return (0);
	line += 0;
	map->size = len;
	return (1);
}

/*
** **************************************************************************
**	int ft_map_chk(int fd, t_w *new_w)
**	First function to check user map size
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
			ft_putstr_fd("GNL error. ", 2);
		if (res == 0)
			break ;
		if (!ft_map_save(ft_strlen(line), line, &w->map))
			return (0);
		ft_strdel(&line);
		i++;
	}
	if (i > MAX_MAP_H || i < MIN_MAP_H)
		return (0);
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
	ft_putstr("usage ./wolf3d ./maps/map.wolf3d:\n\
	\n\tMap width - [4-50]\n\
	Map height - [4-50]\n\
	w - wall block\n\
	o1 - objects[1-4]\n\
	1 - empty blocks with floor and ceiling[1-4]\n\
	p - player\n\
	\n");
}
