/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/07 19:36:45 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	void ft_init_rect(SDL_Rect *rect)
**	Function to make rectangle
** **************************************************************************
*/

void		ft_init_rect(SDL_Rect *rect)
{
	if (rect)
	{
		rect->x = 50;
		rect->y = 50;
		rect->w = 50;
		rect->h = 50;
	}
}

void		ft_draw(t_w *w)
{
	w += 0;
	
}