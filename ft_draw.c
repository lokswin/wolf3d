/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/24 21:23:43 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void				ft_cast_ray(t_w *w)
{
	w += 0;
	//find ray_len when ray hit wall by check each grid of map blocks;
	//check vertical grid intersections if (there is a wall) then stop;
	//
	//check horizontal grid intersections if (there is a wall) then stop;
	//
	//distance to both intersection points is then compared
	//the closer distance is chosen
}

/*
** **************************************************************************
**	void ft_draw(t_w *new_w)
**	Function to draw
** **************************************************************************
*/

void					ft_draw(t_w *w)
{
	int		i;
	int		dist_to_cam;
	int		fov;
	int		ray;
	int		ray_angle;

	i = 0;
	ray = 0;
	fov = 60; 
	ray_angle = deg_to_rad((fov / W));
	//dimension = W * H;
	//cam_mid = W / 2 , H / 2;
	dist_to_cam = (W / 2) / (tan(deg_to_rad(30)));
	while (i > W)
	{
		ft_cast_ray(w);//
		ray += ray_angle;
		i++;
	}
	printf("dist_to_cam=%d\n", dist_to_cam);
	
}
