/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/07 21:25:04 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	int ft_ui(t_w *w, SDL_Event	*e)
**	Second function to handle user input
** **************************************************************************
*/

static void		ft_ui_exp(SDL_Event *e, d_moves *m, double r_speed)
{
	double old_dir_x;
	double old_pl_x;

	old_dir_x = m->dirX;
	old_pl_x = m->planeX;
	if ((e->key.keysym.sym == SDLK_RIGHT) || (e->key.keysym.sym == SDLK_d))
	{
		m->dirX = m->dirX * cos(-r_speed) + m->dirY * sin(r_speed);
		m->dirY = old_dir_x * sin(-r_speed) + m->dirY * cos(r_speed);
		m->planeX = m->planeX * cos(-r_speed) + m->planeY * sin(r_speed);
		m->planeY = old_pl_x * sin(-r_speed) + m->planeY * cos(r_speed);
	}
	if ((e->key.keysym.sym == SDLK_LEFT) || (e->key.keysym.sym == SDLK_a))
	{
		m->dirX = m->dirX * cos(r_speed) - m->dirY * sin(r_speed);
		m->dirY = old_dir_x * sin(r_speed) + m->dirY * cos(r_speed);
		m->planeX = m->planeX * cos(r_speed) - m->planeY * sin(r_speed);
		m->planeY = old_pl_x * sin(r_speed) + m->planeY * cos(r_speed);
	}
}

/*
** **************************************************************************
**	int ft_ui(t_w *w, SDL_Event	*e)
**	First function to handle user input
** **************************************************************************
*/

int				ft_ui(SDL_Event *e, d_moves *m, t_w *w)
{
	double	r_speed;

	r_speed = 0.05;
	if (e->key.keysym.sym == SDLK_ESCAPE)
		return (0);
	if ((e->key.keysym.sym == SDLK_UP) || (e->key.keysym.sym == SDLK_w))
	{
		if (w->map.dig_map[(int)(m->posX + m->dirX * m->mv_speed)]\
		[(int)(m->posY)] == 0)
			m->posX += m->dirX * m->mv_speed;
		if (w->map.dig_map[(int)(m->posX)]\
		[(int)(m->posY + m->dirY * m->mv_speed)] == 0)
			m->posY += m->dirY * m->mv_speed;
	}
	if ((e->key.keysym.sym == SDLK_DOWN) || (e->key.keysym.sym == SDLK_s))
	{
		if (w->map.dig_map[(int)(m->posX - m->dirX * m->mv_speed)]\
		[(int)(m->posY)] == 0)
			m->posX -= m->dirX * m->mv_speed;
		if (w->map.dig_map[(int)(m->posX)]\
		[(int)(m->posY - m->dirY * m->mv_speed)] == 0)
			m->posY -= m->dirY * m->mv_speed;
	}
	ft_ui_exp(e, m, r_speed);
	return (1);
}
