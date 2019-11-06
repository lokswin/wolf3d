
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


	SDL_Texture	*textr;
	textr = NULL;


	config_moves(&m, w);
	config_win(&dw);
	SDL_Event e;
    screen(&dw);//esta funcion la remplazamos creando una ventana
	if(!(textr = IMG_LoadTexture(dw.render, "wall/WALL0.bmp")))
		ft_putstr_fd("err_img_load", 2);
	if (SDL_RenderCopy(dw.render, textr, NULL, NULL))
		ft_sdl_error(w);
	SDL_RenderPresent(dw.render);
	while(1)
    {
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)//close with button
            	break ;
            else if (e.type == SDL_KEYDOWN)//user key input
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
        {//calculate ray position and direction
			c.cameraX = 2 * x / (double)(W_WIN) - 1;
			c.rayDirX = m.dirX + m.planeX * c.cameraX;
			c.rayDirY = m.dirY + m.planeY * c.cameraX;
			c.mapX = (int)m.posX;
			c.mapY = (int)m.posY;
			c.deltaDistX = fabs(1 / c.rayDirX);
			c.deltaDistY = fabs(1 / c.rayDirY);
			c.hit = 0;
			c.side = 2;
            if (c.rayDirX < 0)//calculate step and initial sideDist
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
            while (c.hit == 0)//perform DDA
            {
                if (c.sideDistX < c.sideDistY)//jump to next map square, OR in x-direction, OR in y-direction
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
				    c.hit = 1;//Check if ray has hit a wall
            }
            if (c.side == 0)//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			    c.perpWallDist = (c.mapX - m.posX + (1 - c.stepX) / 2) / c.rayDirX;
            else
			    c.perpWallDist = (c.mapY - m.posY + (1 - c.stepY) / 2) / c.rayDirY;
            c.lineHeight = (int)(H_WIN / c.perpWallDist);//Calculate height of line to draw on screen
            c.drawStart = -c.lineHeight / 2 + H_WIN / 2;//calculate lowest and highest pixel to fill in current stripe
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
            if (c.side == 1)//give x and y sides different brightness
                color = color_get(color.r / 2,color.g / 2, color.b /2, 255);
            verLine(x, &c, color, &dw);//draw the pixels of the stripe as a vertical line
         //FLOOR CASTING //x, y position of the floor texel at the bottom of the wall
      //4 different wall directions possible
      if(c.side == 0 && c.rayDirX > 0)
      {
        c.floorxwall = c.mapX;
        c.floorywall = c.mapY + c.wallx;
      }
      else if(c.side == 0 && c.rayDirX < 0)
      {
        c.floorxwall = c.mapX + 1.0;
        c.floorywall = c.mapY + c.wallx;
      }
      else if(c.side == 1 && c.rayDirY > 0)
      {
        c.floorxwall = c.mapX + c.wallx;
        c.floorywall = c.mapY;
      }
      else
      {
        c.floorxwall = c.mapX + c.wallx;
        c.floorywall = c.mapY + 1.0;
      }
      c.distwall = c.perpWallDist;
      c.distplayer = 0.0;

      if (c.drawEnd < 0)
	  	c.drawEnd = H_WIN; //becomes < 0 when the integer overflows

      //draw the floor from drawEnd to the bottom of the screen
			for(int y = c.drawEnd + 1; y < H_WIN; y++)
			{
				c.currentdist = H_WIN / (2.0 * y - H_WIN); //lookup

				c.floorweight = (c.currentdist - c.distplayer) / (c.distwall - c.distplayer);

				c.currentfloorx = c.floorweight * c.floorxwall + (1.0 - c.floorweight) * m.posX;
				c.currentfloory = c.floorweight * c.floorywall + (1.0 - c.floorweight) * m.posY;

				c.floortexx = (int)(c.currentfloorx * W_TEX) % W_TEX;
				c.floortexy = (int)(c.currentfloory * H_TEX) % H_TEX;

				c.pix = dw.pix;
				
				//floor
				//buffer[y][x] = (SDL_RenderReadPixels()[W_TEX * c.floortexy + c.floortexx] >> 1) & 8355711;
				//ceiling (symmetrical!)
				//buffer[H_WIN - y][x] = texture[6][W_TEX * c.floortexy + c.floortexx];
			}
		}
	  //ft_draw_buff(&dw, buffer[0]);
		
		//for(int x = 0; x < W_WIN; x++) for(int y = 0; y < H_WIN; y++)
	  	//	buffer[y][x] = 0;
		w->datas_win = &dw;
		redraw(&dw);
    }
    return (1);
}
