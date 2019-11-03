#include "wolf3d.h"

void redraw(d_win *w)
{
	SDL_UpdateTexture(w->texture, NULL, w->surf->pixels, w->surf->pitch);
	SDL_RenderClear(w->render);
	SDL_RenderCopy(w->render, w->texture, NULL, NULL);
	SDL_RenderPresent(w->render);
}

void cls(d_win *w)
{
	SDL_UpdateTexture(w->texture, NULL, w->surf->pixels, w->surf->pitch);
	SDL_SetRenderDrawColor(w->render, 0, 0, 0, 0);
	SDL_RenderClear(w->render);
	SDL_RenderPresent(w->render);
	//SDL_Delay(5);

}

int	verLine(int x, t_w *c, struct ColorRGBA color, SDL_Surface	*surf)//Fast vertical line from (x,y1) to (x,y2), with rgb color
{
	int	w = W_WIN;
	int h = H_WIN;
	int y1;
	int y2;
	int y;
	int colorsdl;
	int *bufp;

	y1 = c->drawStart;
	y2 = c->drawEnd;
	if (y2 < y1)//swap y1 and y2
	{
		y1 += y2;
		y2 = y1 - y2;
		y1 -= y2;
	} 
	if (y2 < 0 || y1 >= h || x < 0 || x >= w)//no single point of the line is on screen
		return 0;
	if (y1 < 0)//clip
		y1 = 0;
	if (y2 >= w)//clip
		y2 = h - 1;
	colorsdl = SDL_MapRGBA(c->pix, color.r, color.g, color.b, color.a);
	bufp = (int*)surf->pixels + y1 * surf->pitch / 4 + x;
	y = y1;
	while (y <= y2)
	{
		*bufp = colorsdl;
		bufp += surf->pitch / 4;
		y++;
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
