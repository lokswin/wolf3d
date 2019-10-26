/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/26 20:02:19 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	void ft_sdl_error()
**	Function to printf SDL errors
** **************************************************************************
*/

void			ft_sdl_hook(t_w *w)
{
	SDL_Event	e;
	int			quit;
	
	quit = 0;
	w += 0;
	while (!quit)
	{
    	while (SDL_PollEvent(&e))
		{
        	if (e.type == SDL_QUIT)
			{
            	quit = -1;
        	}
			if (e.type == SDL_KEYDOWN)
   			{
				quit = ft_ui(w, &e);
        	}
			/*
        	if (e.type == SDL_MOUSEBUTTONDOWN)
			{
            	quit = -1;
        	}*/
		}
    }
}
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
	ft_putstr_fd("SDL_Error:", 2);
	ft_putstr_fd(out, 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

/*
** **************************************************************************
**	void ft_sdl_error()
**	Function to printf SDL errors
** **************************************************************************
*/

void		ft_init_rect(SDL_Rect *rect)
{
	if (rect)
	{
		rect->x = 50;
		rect->y = 50;
		rect->w = 350;
		rect->h = 350;
	}
}



/*
** **************************************************************************
**	void ft_sdl_run(t_w *w)
**	Function to run sdl
** **************************************************************************
*/

void				ft_sdl_run(t_w *w)
{
	SDL_Window		*sdl_win;
	SDL_Surface		*screenSurface;
	SDL_DisplayMode *displayMode;
	SDL_Rect		rect;

	sdl_win = NULL;
	screenSurface = NULL;
	displayMode = NULL;
	ft_init_rect(0);
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)//SDL_INIT_VIDEO init sdl
		ft_sdl_error();
	if(SDL_GetDesktopDisplayMode(0, displayMode))// get display
		ft_sdl_error();
	if(!(sdl_win = SDL_CreateWindow("WOLF3D", \
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0))) //get window
		ft_sdl_error();
	printf("sdl_p1\n");
	if(!(screenSurface = SDL_GetWindowSurface(sdl_win)))
		ft_sdl_error();
	if(SDL_FillRect(screenSurface, &rect, 0xFF) != 0)
			ft_sdl_error();
	//if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
	//	ft_sdl_error();
	//SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0xFF));
	if (SDL_UpdateWindowSurface(sdl_win) != 0)
		ft_sdl_error();
	printf("sdl_p2");
	ft_sdl_hook(w);
	w->sdl_win = sdl_win;
	SDL_DestroyWindow(sdl_win);
	SDL_Quit();
}

//SDL_WINDOWPOS_UNDEFINED|SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE
/*if(!(rend = SDL_CreateRenderer(sdl_win, -1, \
			SDL_RENDERER_SOFTWARE | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
				ft_sdl_error();
				SDL_RenderClear(rend);
			SDL_RenderPresent(rend);
			if(!(SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE)))
				ft_sdl_error();*/