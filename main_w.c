
#include "wolf3d.h"

int ft_engine(int **worldMap)
{
	d_moves m;
	d_win dw;
	t_w c;

	config_moves(&m);
	SDL_Event e;
    color_rgb color;
    screen(&dw);//esta funcion la remplazamos creando una ventana
    c.pix = dw.pix;
    while(1)//hasta que no se aplaste esc
    {
	    if (SDL_PollEvent(&e))
	    {
	        if (e.type == SDL_QUIT)
	        {
	            break;
	        }
	        else if (e.type == SDL_KEYDOWN)
	        {
                SDL_Surface *otro_surf;
                SDL_Surface *tmp;
                otro_surf = SDL_CreateRGBSurface(0, W_WIN, H_WIN, 32,
                                                0xFF000000,
                                                0x00FF0000,
                                                0x0000FF00,
                                                0x000000FF);
                tmp = dw.surf;
                dw.surf = otro_surf;
                SDL_FreeSurface(tmp);
                ft_ui(&e, &m, worldMap);

            }
	    }
        for(int x = 0; x < W_WIN; x++)
        {//calculate ray position and direction
			c.cameraX = 2 * x / (double)(W_WIN) - 1;//x ccordinate in camera space
			c.rayDirX = m.dirX + m.planeX * c.cameraX;
			c.rayDirY = m.dirY + m.planeY * c.cameraX;
			c.mapX = (int)m.posX;
			c.mapY = (int)m.posY;
			c.deltaDistX = fabs(1 / c.rayDirX);//en el original se usa abs
			c.deltaDistY = fabs(1 / c.rayDirY);
			c.hit = 0;//???
			//c.side = 2;//
            if (c.rayDirX < 0)//calculate step and initial sideDist
            {
			c.stepX = -1;
			c.sideDistX = (m.posX - c.mapX) * c.deltaDistX;
            }
            else
            {
			c.stepX = 1;
			c.sideDistX = (c.mapX + 1.0 - m.posX) * c.deltaDistX;
            }
            if (c.rayDirY < 0)
            {
			c.stepY = -1;
			c.sideDistY = (m.posY - c.mapY) * c.deltaDistY;
            }
            else
            {
			c.stepY = 1;
			c.sideDistY = (c.mapY + 1.0 - m.posY) * c.deltaDistY;
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
                if (worldMap[c.mapX][c.mapY] > 0) //Check if ray has hit a wall
				    c.hit = 1;
            }
            if (c.side == 0)//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			    c.perpWallDist = (c.mapX - m.posX + (1 - c.stepX) / 2) / c.rayDirX;
            else
			    c.perpWallDist = (c.mapY - m.posY + (1 - c.stepY) / 2) / c.rayDirY;
		    c.lineHeight = (int)(H_WIN / c.perpWallDist);//Calculate height of line to draw on screen
		    c.drawStart = -c.lineHeight / 2 + H_WIN / 2; //calculate lowest and highest pixel to fill in current stripe
            if(c.drawStart < 0)c.drawStart = 0;
		        c.drawEnd = c.lineHeight / 2 + H_WIN / 2;
            if(c.drawEnd >= H_WIN)
                c.drawEnd = H_WIN - 1;
            if (worldMap[c.mapX][c.mapY] == 5)
                color = color_get(255,0,0,255);
            else if (worldMap[c.mapX][c.mapY] == 2)
                color = color_get(0,255,0,255);
            else if (worldMap[c.mapX][c.mapY] == 3)
                color = color_get(255,255,255,255);
            else if (worldMap[c.mapX][c.mapY] == 4)
                color = color_get(0,0,255,255);
            else
                color = color_get(255,255,224,255);
            if (c.side == 1) //give x and y sides different brightness
                color = color_get(color.r / 2,color.g / 2, color.b /2, 255);
            verLine(x, &c, color, &dw);//draw the pixels of the stripe as a vertical line
        }
        redraw(&dw);
        //cls(&dw);

    }
}