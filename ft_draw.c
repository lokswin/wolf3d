/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/29 17:58:40 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static void ft_calc_dist(t_w *w)
**	Function to calculate ray distance to walls
** **************************************************************************
*/

static int		ft_calc_dist(t_w *w)
{
	int			p_hor;
	int			p_vert;

	p_hor = 0;
	p_vert = 0;
	p_hor = sqrt(pow((w->px - w->hor_point.x), 2) + pow((w->py - w->vert_point.y), 2));
	p_vert = sqrt(pow((w->px - w->vert_point.x), 2) + pow((w->py - w->vert_point.y), 2));
	if (p_hor > p_vert)//distance to both intersection points is then compear
		return (p_vert);
	else
		return (p_hor);
}

/*
** **************************************************************************
**	static void ft_check_hor(t_w *w)
**	Function to check horizontal grid intersections if
**	(there is a wall) then stop and return distance;
** **************************************************************************
*/

static int		ft_check_hor(t_w *w, int i)
{
	int			facing;
	int			xa;
	int			ya;

	xa = WALL_SIZE / tan(w->ray_angle);
	facing = 0;
	if (i > 0)//all intresection except first
	{
		if (facing) //find ray facing(up/down)
			ya = -WALL_SIZE;
		else
			ya = WALL_SIZE;
		w->hor_point.x = (w->hor_point.x + xa) / WALL_SIZE;
		w->hor_point.y = (w->hor_point.y + ya) / WALL_SIZE;
	}
	else//first intresection
	{
		if (facing) //find ray facing(up/down)
			w->hor_point.y = ((floor(w->py / WALL_SIZE) * WALL_SIZE) - 1) / WALL_SIZE;//up|find out the grid coordinate of y for first cross
		else
			w->hor_point.y = ((floor(w->py / WALL_SIZE) * WALL_SIZE) + WALL_SIZE) / WALL_SIZE; //down|find out the grid coordinate of y for first cross
		w->hor_point.x = (w->px + (w->py - w->hor_point.y) / tan(w->ray_angle)) / WALL_SIZE;
	}
	//If there is no wall, extend the to the next intersection point.
	return (1);
}

/*
** **************************************************************************
**	static void ft_check_vert(t_w *w)
**	Function to check vertical grid intersections if
**	(there is a wall) then stop and return distance;
** **************************************************************************
*/

static int		ft_check_vert(t_w *w, int i)
{
	int			facing;
	int			xa;
	int			ya;

	ya = WALL_SIZE * tan(w->ray_angle);
	facing = 0;
	if (i > 0)//all intresection except first
	{
		if (facing) //find ray facing(right/left)
			xa = -WALL_SIZE;//right
		else
			xa = WALL_SIZE;//left
		w->vert_point.x = (w->vert_point.x + xa) / WALL_SIZE;
		w->vert_point.y = (w->vert_point.y + ya) / WALL_SIZE;
	}
	else//first intresection
	{
		if (facing) //find ray facing(right/left)
			w->vert_point.x = ((floor(w->px / WALL_SIZE) * WALL_SIZE) + WALL_SIZE) / WALL_SIZE;//right|find out the grid coordinate of y for first cross
		else
			w->vert_point.x = ((floor(w->px / WALL_SIZE) * WALL_SIZE) - 1) / WALL_SIZE; //left|find out the grid coordinate of y for first cross
		w->vert_point.y = (w->py + (w->px - w->vert_point.x) * tan(w->ray_angle)) / WALL_SIZE;
	}
	//If there is a wall on the grid, stop and calculate the distance.
	
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
	int		facing;
	int		cross;
	int		d_dist;
	int		c_dist;
	int		i;

	d_dist = 0;
	c_dist = 0;
	i = 0;
	facing = 0;
	cross = 0;//how many intersection ray has with blocks
	//find ray_len when ray hit wall by check each grid of map blocks;
	ft_check_vert(w, i);
	ft_check_hor(w, i);
	d_dist = ft_calc_dist(w);
	if (facing)
		c_dist = d_dist * cos(w->ray_angle / 2);
	else
		c_dist = d_dist * cos(-(w->ray_angle / 2));
	
	//the closer distance is chosen
	//check there is a wall or not
	//if not then go next block
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


	i = 0;
	ray = 0;
	fov = 60; 
	w->player_angle = deg_to_rad((fov / W_WIN));
	//dimension = W * H;
	//cam_mid = W / 2 , H / 2;
	dist_to_cam = (W_WIN / 2) / (tan(deg_to_rad(30)));
	while (i > W_WIN)
	{
		ft_cast_ray(w);//cast new ray for every pixel
		i++;
	}
	printf("dist_to_cam=%d\n", dist_to_cam);
	
}
