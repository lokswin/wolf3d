/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/26 20:04:14 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	int ft_ui(t_w *w, SDL_Event	*e)
**	Function to handle user input
** **************************************************************************
*/

int			ft_ui(t_w *w, SDL_Event	*e)
{
	w += 0;
	if (e->key.keysym.sym == SDLK_ESCAPE)
	{
		return(-1);
	}
	if ((e->key.keysym.sym == SDLK_UP) || (e->key.keysym.sym == SDLK_w))
	{
		printf("move up\n");
	}
	if ((e->key.keysym.sym == SDLK_DOWN) || (e->key.keysym.sym == SDLK_s))
	{
		//move down
	}
	if ((e->key.keysym.sym == SDLK_RIGHT) || (e->key.keysym.sym == SDLK_d))
	{
		//move right
	}
	if ((e->key.keysym.sym == SDLK_LEFT) || (e->key.keysym.sym == SDLK_a))
	{
		//move left
	}
	return(0);	
}