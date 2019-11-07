/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:37:35 by drafe             #+#    #+#             */
/*   Updated: 2019/11/07 21:27:14 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_redraw(d_win *w)
{
	if (SDL_UpdateTexture(w->texture, NULL, \
	w->surf->pixels, w->surf->pitch) < 0)
		ft_sdl_error(w);
	if (SDL_RenderCopy(w->render, w->texture, NULL, NULL))
		ft_sdl_error(w);
	SDL_RenderPresent(w->render);
}

int			ft_vert_ln(int x, t_w *c, color_rgb color, d_win *dw)
{
	int		colorsdl;
	int		*bufp;
	int		y;

	if (c->drawEnd < c->drawStart)
	{
		c->drawStart += c->drawEnd;
		c->drawEnd = c->drawStart - c->drawEnd;
		c->drawStart -= c->drawEnd;
	}
	if (c->drawEnd < 0 || c->drawStart >= H_WIN || x < 0 || x >= W_WIN)
		return (0);
	if (c->drawStart < 0)
		c->drawStart = 0;
	if (c->drawEnd >= W_WIN)
		c->drawEnd = H_WIN - 1;
	colorsdl = SDL_MapRGBA(dw->pix, color.r, color.g, color.b, color.a);
	bufp = (int*)dw->surf->pixels + c->drawStart * dw->surf->pitch / 4 + x;
	y = c->drawStart - 1;
	while (++y <= c->drawEnd)
	{
		*bufp = colorsdl;
		bufp += dw->surf->pitch / 4;
	}
	return (1);
}

color_rgb	color_get(int r, int g, int b, int a)
{
	color_rgb color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}
