/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/06 18:56:23 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	int ft_load_tex()
**	Function to load textures
** **************************************************************************
*/

int ft_load_tex()
{
	int				i;
	unsigned long	tw;
	unsigned long	th;
	unsigned long	error;

	i = 0;
	while(i < 8)
	{
		texture[i].resize(W_TEX * H_TEX);
		
		error |= loadImage(texture[0], tw, th, "wall/eagle.png");
		error |= loadImage(texture[1], tw, th, "wall/redbrick.png");
		error |= loadImage(texture[2], tw, th, "wall/purplestone.png");
		error |= loadImage(texture[3], tw, th, "wall/greystone.png");
		error |= loadImage(texture[4], tw, th, "wall/bluestone.png");
		error |= loadImage(texture[5], tw, th, "wall/mossy.png");
		error |= loadImage(texture[6], tw, th, "wall/wood.png");
		error |= loadImage(texture[7], tw, th, "wall/colorstone.png");
		if(error)
		{
			ft_putstr_fd("error loading images\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}