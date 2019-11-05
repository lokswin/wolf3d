#include "wolf3d.h"

void redraw(d_win *dw)
{
    SDL_Texture *newTexture;
    SDL_Surface *surface_render;
    //SDL_SetRenderDrawColor(dw->render, 0, 0, 0, 255);
    //SDL_UpdateTexture(dw->texture, NULL, dw->isurf->pixels, dw->isurf->pitch);
    //SDL_RenderCopy(dw->render, dw->texture, NULL, NULL);
   // SDL_RenderClear(dw->render);

    //surface_render = SDL_LoadBMP("wolfwall/WALL8.bmp");
    //newTexture = SDL_CreateTextureFromSurface(dw->render, surface_render);
    //SDL_RenderCopy(dw->render, newTexture, NULL, NULL);
    //SDL_RenderPresent(dw->render);


    SDL_UpdateTexture(dw->texture, NULL, dw->surf->pixels, dw->surf->pitch);
    SDL_RenderCopy(dw->render, dw->texture, NULL, NULL);
    SDL_RenderPresent(dw->render);
}

int	verLine(int x, t_w *c, color_rgb color, d_win *dw)//Fast vertical line from (x,y1) to (x,y2), with rgb color
{
	int w = W_WIN;
	int h = H_WIN;
    int * bufp;

	if (c->drawEnd < c->drawStart)
	{
        c->drawStart += c->drawEnd;;
        c->drawEnd = c->drawStart - c->drawEnd;;
        c->drawStart -= c->drawEnd;;
	} //swap y1 and c->drawEnd;
	if (c->drawEnd < 0 || c->drawStart >= h || x < 0 || x >= w)
	    return 0; //no single point of the line is on screen
	if (c->drawStart < 0)
	    c->drawStart = 0; //clip
	if (c->drawEnd >= w)
	    c->drawEnd = h - 1; //clip

	int colorSDL = SDL_MapRGBA(dw->pix, color.r, color.g, color.b, color.a);

	bufp = (int*)dw->surf->pixels + c->drawStart * dw->surf->pitch / 4 + x;
	for (int y = c->drawStart; y <= c->drawEnd; y++)
	{
		*bufp = colorSDL;
		bufp += dw->surf->pitch / 4;
	}
	return 1;
}

color_rgb color_get(int r, int g, int b, int a)
{
	color_rgb color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return(color);
}
