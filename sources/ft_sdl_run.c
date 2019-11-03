/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/11/03 16:56:35 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	void ft_sdl_hook(t_w *w)
**	Function to keep sdl cycle runnig
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
            	quit = -1;
			//if (e.type == SDL_KEYDOWN)
			//	quit = ft_ui(w, &e);
			/*
        	if (e.type == SDL_MOUSEBUTTONDOWN)
			{
            	quit = -1;
        	}*/
		}

    }
	ft_putstr("Have a nice day!\n");
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
**	void ft_sdl_run(t_w *w)
**	Function to run sdl
** **************************************************************************
*/


/*
void				ft_sdl_run(t_w *w)
{
	SDL_DisplayMode *displayMode;
	SDL_Rect		rect;

	displayMode = NULL;
	ft_init_rect(&rect);
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)//main sdl init 
		ft_sdl_error();
	if(SDL_GetDesktopDisplayMode(0, displayMode))//choose display for work
		ft_sdl_error();
	if(!(w->sdl_win = SDL_CreateWindow("WOLF3D", 0, 0, W_WIN, H_WIN, 0)))//create window
		ft_sdl_error();
	if(!(w->w_surf = SDL_GetWindowSurface(w->sdl_win)))//get window surface
		ft_sdl_error();
	if(SDL_FillRect(w->w_surf, &rect, SDL_MapRGB(w->w_surf->format, 0xFF, 0x00, 0xFF)) != 0)//draw some rectangle
			ft_sdl_error();
	if (SDL_UpdateWindowSurface(w->sdl_win) != 0)//update window after draw rectangle
		ft_sdl_error();//update window after draw rectangle
		ft_sdl_error();
	ft_ray(w);
	ft_sdl_hook(w);
	SDL_DestroyWindow(w->sdl_win);
	SDL_Quit();
}
*/

/*

//SDL_PixelFormat

//if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
	//	ft_sdl_error();
	//SDL_MapRGB(w->w_surf->format, 0xFF, 0x00, 0xFF));
//SDL_WINDOWPOS_UNDEFINED|SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE
SDL_Init(SDL_INIT_EVERYTHING) < 0)//SDL_INIT_VIDEO
if(!(rend = SDL_CreateRenderer(sdl_win, -1, \
			SDL_RENDERER_SOFTWARE | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
				ft_sdl_error();
				SDL_RenderClear(rend);
			SDL_RenderPresent(rend);
			if(!(SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE)))
				ft_sdl_error();
*/