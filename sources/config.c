#include "wolf3d.h"

void config_moves(d_moves *m, t_w *w)
{
    /*m->posX = 6;
    m->posY = 3;*/
    m->posX = w->map.p_x + 2;//start position
    m->posY = w->map.p_y + 2;
    m->dirX = -1;//initial direction
    m->dirY = 0;
    m->planeX = 0;
    m->planeY = 0.66;
}

void config_win(struct data_win *dw)
{
    dw += 0;
}