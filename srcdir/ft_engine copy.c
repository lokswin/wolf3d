
#include "wolf3d.h"

Uint32 buffer[H_WIN][W_WIN];

void	ft_draw_buff(d_win *dw, Uint32 *bufdrw)
{
	Uint32 *bufp;
	bufp = (Uint32*)dw->surf->pixels;

	for(int y = 0; y < H_WIN; y++)
	{
		for(int x = 0; x < W_WIN; x++)
		{
			bufp[x] = bufdrw[y * W_WIN + x];
			bufp++;
		}
		bufp += dw->surf->pitch / 4;
		bufp -= W_WIN;
	}
}

int ft_engine(t_w *w)
{
	d_moves     m;
	d_win       dw;
	t_w         c;
    SDL_Surface *otro_surf;
    SDL_Surface *tmp;
    color_rgb   color;
	SDL_Event	e;
	ft_config_moves(&m, w);
    ft_screen(&dw);
	while(1)
    {
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            	break ;
            else if (e.type == SDL_KEYDOWN)
            {
                otro_surf = SDL_CreateRGBSurface(0, W_WIN, H_WIN, 32, \
                0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
                tmp = dw.surf;
                dw.surf = otro_surf;
                SDL_FreeSurface(tmp);
                if(!ft_ui(&e, &m, w))
                    break ;
            }
        }
        for(int x = 0; x < W_WIN; x++)
        {
			c.cameraX = 2 * x / (double)(W_WIN) - 1;
			c.rayDirX = m.dirX + m.planeX * c.cameraX;
			c.rayDirY = m.dirY + m.planeY * c.cameraX;
			c.mapX = (int)m.posX;
			c.mapY = (int)m.posY;
			c.deltaDistX = fabs(1 / c.rayDirX);
			c.deltaDistY = fabs(1 / c.rayDirY);
			c.hit = 0;
			c.side = 2;
            if (c.rayDirX < 0)
            {
                c.stepX = -1;
                c.sideDistX = (m.posX - c.mapX) * c.deltaDistX;
            }
            else
            {
                c.stepX = 1;
                c.sideDistX = (c.mapX + 1 - m.posX) * c.deltaDistX;
            }
            if (c.rayDirY < 0)
            {
                c.stepY = -1;
                c.sideDistY = (m.posY - c.mapY) * c.deltaDistY;
            }
            else
            {
                c.stepY = 1;
                c.sideDistY = (c.mapY + 1 - m.posY) * c.deltaDistY;
            }
            while (c.hit == 0)
            {
                if (c.sideDistX < c.sideDistY)
                {
                    c.sideDistX += c.deltaDistX;
                    c.mapX += c.stepX;
                    c.side = 0;
                }
                else
                {
                    c.sideDistY += c.deltaDistY;
                    c.mapY += c.stepY;
                    c.side = 1;
                }
                if (w->map.dig_map[c.mapX][c.mapY] > 0)
				    c.hit = 1;
            }
            if (c.side == 0)
			    c.perpWallDist = (c.mapX - m.posX + (1 - c.stepX) / 2) / c.rayDirX;
            else
			    c.perpWallDist = (c.mapY - m.posY + (1 - c.stepY) / 2) / c.rayDirY;
            c.lineHeight = (int)(H_WIN / c.perpWallDist);
            c.drawStart = -c.lineHeight / 2 + H_WIN / 2;
            if(c.drawStart < 0)
				c.drawStart = 0;
		    c.drawEnd = c.lineHeight / 2 + H_WIN / 2;
            if(c.drawEnd >= H_WIN)
				c.drawEnd = H_WIN - 1;
            if (w->map.dig_map[c.mapX][c.mapY] == 5)
				color = color_get(255,0,0,255);
            else if (w->map.dig_map[c.mapX][c.mapY] == 2)
				color = color_get(0,255,0,255);
        	else if (w->map.dig_map[c.mapX][c.mapY] == 3)
				color = color_get(255,255,255,255);
			else if (w->map.dig_map[c.mapX][c.mapY] == 4)
				color = color_get(0,0,255,255);
			else
				color = color_get(255,255,224,255);
            if (c.side == 1)
                color = color_get(color.r / 2,color.g / 2, color.b /2, 255);
            ft_vert_ln(x, &c, color, &dw);
    	}
		w->datas_win = &dw;
		//printf("m.posX=%f m.posy=%f\n", m.posX, m.posY);
		ft_redraw(&dw);
	}
    return (1);
}
