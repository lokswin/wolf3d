/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/31 21:04:17 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static int ft_map_save(int	ln_nb, char *line, t_map *map)
**	Function to save map
** **************************************************************************
*/

static int		ft_map_save(char arr[MAX_MAP_H][MAX_MAP_W], t_map *map)
{
	int		i;

	i = 0;
	while(i < map->size)
	{
		printf("ft_map_save: ln_nb=%d line=%s\n", i, arr[i]);
		if (i != 0)
		{
			if(!(map->dig_map[i] = (int*)malloc(sizeof(int) * 20)))
			{
				ft_putstr_fd("map malloc error #2", 2);
				return (0);
			}
		}
		else
			if(!(map->dig_map = (int**)malloc(sizeof(int*) * 20)) || \
			!(map->dig_map[i] = (int*)malloc(sizeof(int) * 20)))
			{
				ft_putstr_fd("map malloc error #1", 2);
				return (0);
			}
		ft_save_line(arr[i], map->dig_map[i], map->size);
		i++;
	}
	return (1);
}

/*
** **************************************************************************
**	static int ft_map_chk_exp(int len, char *line)
**	Second function to check user map symbols
** **************************************************************************
*/

static int		ft_map_chk_exp(int len, char *line, int *size)
{
	int			i;

	i = 0;
	line += 0;
	if ((len > MAX_MAP_W) || (len < MIN_MAP_W))
			return (0);
	printf("\nsize=%d\n", *size);
	if (len > size[0])
		size[0] = len;
	printf("\nsize=%d\n", *size);
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
	char	arr[MAX_MAP_H][MAX_MAP_W];
	char	*line;
	int		res;
	int		i;

	i = 0;
	res = 1;
	w->map.size = 0;
	while (i < MAX_MAP_H + 1)
	{
		if ((res = ft_get_next_line(fd, &line)) == -1)
			ft_putstr_fd("GNL error. ", 2);
		if (res == 0)
			break ;
		if (!ft_map_chk_exp(ft_strlen(line), line, &w->map.size))
			return (0);
		ft_strcpy(arr[i], line);
		free(line);
		i++;
	}
	if (i > w->map.size)
		w->map.size = i;
	if ((i > MAX_MAP_H) || (i < MIN_MAP_H) || !ft_map_save(arr, &w->map))
		return (0);
	ft_map_save(arr, &w->map);
	return(1);
}
