/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/25 18:27:38 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	void ft_sdl_error()
**	Function to printf SDL errors
** **************************************************************************
*/

void		ft_sdl_error()
{
	const char	*out;

	out = SDL_GetError();
	ft_putstr_fd("SDL could not initialize! SDL_Error:", 2);
	ft_putstr_fd(out, 2);
	ft_putstr_fd("\n", 2);
}

/*
** **************************************************************************
**	void ft_sdl_run(t_w *w)
**	Function to run sdl
** **************************************************************************
*/

void				ft_sdl_run(t_w *w)
{
	SDL_Window*		sdl_win;
	SDL_Surface*	screenSurface;

	sdl_win = NULL;
	screenSurface = NULL;
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_sdl_error();
	else
	{
		if(!(sdl_win = SDL_CreateWindow("WOLF3D", 0, 0, W, H, SDL_WINDOW_SHOWN)))
			ft_sdl_error();
		else
		{
			printf("sdl_p1\n");
			screenSurface = SDL_GetWindowSurface(sdl_win);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(sdl_win);
			printf("sdl_p2");
			SDL_Delay(5000);
		}
	}
	w->sdl_win = sdl_win;
	SDL_DestroyWindow(sdl_win);
	SDL_Quit();
}