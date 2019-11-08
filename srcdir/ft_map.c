/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/07 21:59:38 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static int ft_save(char arr[MAX_MAP_H + 3][MAX_MAP_W + 3], t_map *map)
**	Function to save map
** **************************************************************************
*/

static int	ft_save(char arr[MAX_MAP_H + 3][MAX_MAP_W + 3], t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->size)
		if (i != 0)
		{
			if (!(map->dig_map[i] = (int*)malloc(sizeof(int) * map->size)))
			{
				ft_putstr_fd("map malloc error #2", 2);
				return (0);
			}
			ft_save_line(arr[i - 1], map->dig_map[i], map->size);
		}
		else
		{
			if (!(map->dig_map = (int**)malloc(sizeof(int*) * map->size)) || \
			!(map->dig_map[i] = (int*)malloc(sizeof(int) * map->size)))
			{
				ft_putstr_fd("map malloc error #1", 2);
				return (0);
			}
			ft_save_line(NULL, map->dig_map[0], map->size);
		}
	return (1);
}

/*
** **************************************************************************
**	static int ft_map_chk_exp(int file_w, int file_h, char *line, t_map *map)
**	Second function to check user map symbols
** **************************************************************************
*/

static int	ft_map_chk_exp(int file_w, int file_h, char *line, t_map *map)
{
	int	i;

	i = -1;
	if ((file_w >= MAX_MAP_W) || (file_w <= MIN_MAP_W) \
	|| (file_h > MAX_MAP_H))
		return (0);
	if (file_w > map->size)
		map->size = file_w + 3;
	if (file_h > map->size)
		map->size = file_h + 3;
	while (++i < file_w)
		if (line[i] == 'p')
		{
			map->pl += 1;
			map->p_x = (double)file_h;
			map->p_y = (double)i;
		}
	return (1);
}

/*
** **************************************************************************
**	int		ft_map_chk(int fd, t_w *w)
**	First function to check user map size
** **************************************************************************
*/

int			ft_map_chk(int fd, t_w *w)
{
	char	arr[MAX_MAP_H + 3][MAX_MAP_W + 3];
	char	*line;
	int		gnl_res;
	int		file_h;

	file_h = -1;
	gnl_res = 1;
	while (file_h++ < MAX_MAP_H + 1)
	{
		if ((gnl_res = ft_get_next_line(fd, &line)) == -1)
			ft_putstr_fd("GNL error. ", 2);
		if ((gnl_res == 0) || (gnl_res == -1))
		{
			ft_strdel(&line);
			break ;
		}
		if (!ft_map_chk_exp(ft_strlen(line), file_h, line, &w->map))
			return (0);
		ft_strcpy(arr[file_h], line);
		ft_strdel(&line);
	}
	if ((file_h <= MIN_MAP_H) || (w->map.pl != 1) || !ft_save(arr, &w->map))
		return (0);
	return (file_h);
}
