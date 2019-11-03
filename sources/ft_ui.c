/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/03 19:25:59 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	int ft_ui(t_w *w, SDL_Event	*e)
**	Function to handle user input
** **************************************************************************
*/

int			ft_ui(SDL_Event	*e, d_moves *m, t_w *w)
{
	double moveSpeed = 0.064;//frameTime * 5.0; //the constant value is in squares/second
	double rotSpeed = 0.05; //the constant value is in radians/second

	if (e->key.keysym.sym == SDLK_ESCAPE)
	{
		printf("esc\n");
		e->type = SDL_QUIT;
		return(-1);
	}
	if ((e->key.keysym.sym == SDLK_UP) || (e->key.keysym.sym == SDLK_w))
	{
		printf("move up\n");
		if(w->map.dig_map[(int)(m->posX + m->dirX * moveSpeed)][(int)(m->posY)] == 0) m->posX += m->dirX * moveSpeed;
		if(w->map.dig_map[(int)(m->posX)][(int)(m->posY + m->dirY * moveSpeed)] == 0) m->posY += m->dirY * moveSpeed;
	}
	if ((e->key.keysym.sym == SDLK_DOWN) || (e->key.keysym.sym == SDLK_s))
	{
		printf("move down\n");
		if(w->map.dig_map[(int)(m->posX - m->dirX * moveSpeed)][(int)(m->posY)] == 0) m->posX -= m->dirX * moveSpeed;
		if(w->map.dig_map[(int)(m->posX)][(int)(m->posY - m->dirY * moveSpeed)] == 0) m->posY -= m->dirY * moveSpeed;
	}
	if ((e->key.keysym.sym == SDLK_RIGHT) || (e->key.keysym.sym == SDLK_d))//NOT WORKING, need to check formula
	{
		printf("move right\n");
		double oldDirX = m->dirX;
		m->dirX = m->dirX * cos(-rotSpeed) + m->dirY * sin(rotSpeed);
		m->dirY = oldDirX * sin(-rotSpeed) + m->dirY * cos(rotSpeed);
		double oldPlaneX = m->planeX;
		m->planeX = m->planeX * cos(-rotSpeed) + m->planeY * sin(rotSpeed);
		m->planeY = oldPlaneX * sin(-rotSpeed) + m->planeY * cos(rotSpeed);
		/*double oldDirX = m->dirX;
		m->dirX = m->dirX * cos(rotSpeed) - m->dirY * sin(-rotSpeed);
		m->dirY = oldDirX * sin(rotSpeed) + m->dirY * cos(-rotSpeed);
		double oldPlaneX = m->planeX;
		m->planeX = m->planeX * cos(rotSpeed) - m->planeY * sin(-rotSpeed);
		m->planeY = oldPlaneX * sin(rotSpeed) + m->planeY * cos(-rotSpeed);*/
	}
	if ((e->key.keysym.sym == SDLK_LEFT) || (e->key.keysym.sym == SDLK_a))
	{
		printf("move left\n");
		double oldDirX = m->dirX;
		m->dirX = m->dirX * cos(rotSpeed) - m->dirY * sin(rotSpeed);
		m->dirY = oldDirX * sin(rotSpeed) + m->dirY * cos(rotSpeed);
		double oldPlaneX = m->planeX;
		m->planeX = m->planeX * cos(rotSpeed) - m->planeY * sin(rotSpeed);
		m->planeY = oldPlaneX * sin(rotSpeed) + m->planeY * cos(rotSpeed);
	}
	if (e->key.keysym.sym == SDLK_r)//return
	{
		printf("return\n");
		config_moves(m, w);
	}
	return(1);	
}