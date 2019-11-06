
#include "wolf3d.h"

void		ft_sdl_error(d_win *dw)
{
	const char	*out;

	out = SDL_GetError();
	ft_putstr_fd("SDL_Error:", 2);
	ft_putstr_fd(out, 2);
	ft_putstr_fd("\n", 2);
	if (dw->texture)
		SDL_DestroyTexture(dw->texture);
	if (dw->render)
		SDL_DestroyRenderer(dw->render);
	if (dw->sdl_win)
		SDL_DestroyWindow(dw->sdl_win);
	if (dw->surf)
		SDL_FreeSurface(dw->surf);
	SDL_Quit();
	exit(-1);
}

void screen(d_win *dw)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_sdl_error(dw);
	if(!(dw->sdl_win = SDL_CreateWindow("wolf project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W_WIN, H_WIN, SDL_WINDOW_OPENGL)))// || (dw->sdl_win == NULL)
		ft_sdl_error(dw);
	if(!(dw->render = SDL_CreateRenderer(dw->sdl_win, -1, 0)))// || (dw->render == NULL)
		ft_sdl_error(dw);
	//dw->isurf = SDL_GetWindowSurface(dw->sdl_win);
	//if(!(dw->isurf = SDL_GetWindowSurface(dw->sdl_win)))
	//	ft_sdl_error(dw);
	if(!(dw->surf = SDL_CreateRGBSurface(0, W_WIN, H_WIN, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF)))
		ft_sdl_error(dw);
	if(!(dw->texture = SDL_CreateTexture(dw->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, W_WIN, H_WIN)))
		ft_sdl_error(dw);
	//if (SDL_SetTextureBlendMode(dw->texture, SDL_BLENDMODE_BLEND) < 0)
	//	ft_sdl_error(dw);
	dw->pix = dw->surf->format;
	if (dw->pix  == NULL)
		ft_sdl_error(dw);
}