/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/28 22:15:55 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static void ft_check_hori(t_w *w)
**	Function to check horizontal grid intersections if
**	(there is a wall) then stop and return distance;
** **************************************************************************
*/

static int		ft_check_hori(t_w *w)
{
	int			xa;
	int			ya;

	xa = WALL_SIZE / tan(w->ray_angle);
	ya = 64;
	w->px = w->px + xa;
	w->py = w->py + ya;
	return (1);
}

/*
** **************************************************************************
**	static void ft_check_vert(t_w *w)
**	Function to check vertical grid intersections if
**	(there is a wall) then stop and return distance;
** **************************************************************************
*/

static int		ft_check_vert(t_w *w)
{	
	t_cross		point1;
	int			facing;
	int			xa;
	int			ya;

	xa = 64;
	ya = WALL_SIZE * tan(w->ray_angle);
	facing = 0;
	w->px = w->px + xa;
	w->py = w->py + ya;
	if (facing) //find ray facing(up/down)
		point1.y = (floor(w->py / 64) * 64) - 1; //find out the grid coordinate of y
	else
		point1.y = (floor(w->py / 64) * 64) + 64; //find out the grid coordinate of y
	return (1);
}

/*
** **************************************************************************
**	static void ft_cast_ray(t_w *w)
**	Function to cast ray
** **************************************************************************
*/

static void		ft_cast_ray(t_w *w)
{
	t_cross		point1;
	int			dist;

	dist = 0;
	//find ray_len when ray hit wall by check each grid of map blocks;
	if (ft_check_vert(w) > ft_check_hori(w))
		dist = ft_check_vert(w);
	else
		dist = ft_check_hori(w);
	
	//distance to both intersection points is then compared
	//the closer distance is chosen
}

/*
** **************************************************************************
**	void ft_draw(t_w *new_w)
**	Function to draw
** **************************************************************************
*/

void			ft_draw(t_w *w)
{
	int			i;
	int			dist_to_cam;
	int			fov;
	int			ray;
	int			ray_angle;


	i = 0;
	ray = 0;
	fov = 60; 
	ray_angle = deg_to_rad((fov / W_WIN));
	//dimension = W * H;
	//cam_mid = W / 2 , H / 2;
	dist_to_cam = (W_WIN / 2) / (tan(deg_to_rad(30)));
	while (i > W_WIN)
	{
		ft_cast_ray(w);//cast new ray for every pixel
		ray += ray_angle;
		i++;
	}
	printf("dist_to_cam=%d\n", dist_to_cam);
	
}
