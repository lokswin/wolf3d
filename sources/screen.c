
#include "wolf3d.h"


void screen(d_win *dw)
{
	dw->fullscreen = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Unable to init SDL: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
	if (dw->fullscreen == 1)
		dw->sdl_win = SDL_CreateWindow("wolf project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dw->w, dw->h, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
	else
		dw->sdl_win = SDL_CreateWindow("wolf project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dw->w, dw->h, SDL_WINDOW_OPENGL);
	if (dw->sdl_win == NULL)
	{
		printf("Unable to set video: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
	dw->render = SDL_CreateRenderer(dw->sdl_win, -1, 0);
	if (dw->render == NULL)
	{
		printf("Unable to set renderer: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
	dw->surf = SDL_CreateRGBSurface(0, dw->w, dw->h, 32,
								0xFF000000,
								0x00FF0000,
								0x0000FF00,
								0x000000FF);
	if (dw->surf == NULL)
	{
		printf("Unable to set surface: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
	dw->texture = SDL_CreateTexture(dw->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, dw->w, dw->h);
	if (dw->texture == NULL)
	{
		printf("Unable to set texture: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
	SDL_SetTextureBlendMode(dw->texture, SDL_BLENDMODE_BLEND);
	dw->pix = dw->surf->format;
	if (dw->pix  == NULL)
	{
		printf("Unable to set pixel format: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
}