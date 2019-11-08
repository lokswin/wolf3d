/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/08 19:28:01 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	void ft_put_map_man()
**	Function to print map man
** **************************************************************************
*/

void			ft_put_map_man(void)
{
	ft_putstr("usage ./wolf3d path_to_map\n\
	\n\tMap width - [4-50]\n\
	Map height - [4-50]\n\
	w - wall block\n\
	o1 - objects[1-4]\n\
	1 - empty blocks with floor and ceiling[1-4]\n\
	p - player\n");
}

/*
** **************************************************************************
**	static void ft_init_wall(int *ptr, int size)
**	Function to place walls everywhere
** **************************************************************************
*/

static void		ft_init_wall(int *ptr, int size)
{
	int			i;

	i = 0;
	while (i < (size + 1))
	{
		ptr[i] = 2;
		i++;
	}
}

/*
** **************************************************************************
**	int ft_save_line(char *line, int *ptr, int size)
**	Function to save one line
** **************************************************************************
*/

int				ft_save_line(char *line, int *ptr, int size)
{
	int			i;

	i = -1;
	ft_init_wall(ptr, size);
	while (++i < size)
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
	return (1);
}
