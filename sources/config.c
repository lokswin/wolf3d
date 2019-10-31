#include "wolf3d.h"

void config_moves(d_moves *m)
{
m->posX = 22;//start position
m->posY = 12;
m->dirX = -1;//initial direction
m->dirY = 0;
m->planeX = 0;
m->planeY = 0.66;
}

void config_win(struct data_win *dw)
{
dw->fullscreen = 0;
dw->w = 512;
dw->h = 384;
}