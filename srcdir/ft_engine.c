#include "wolf3d.h"

void ft_side(t_w *c, d_moves *m)
{
	if (c->rayDirX < 0)
	{
		c->stepX = -1;
		c->sideDistX = (m->posX - c->mapX) * c->deltaDistX;
	}
	else
	{
		c->stepX = 1;
		c->sideDistX = (c->mapX + 1 - m->posX) * c->deltaDistX;
	}
	if (c->rayDirY < 0)
	{
		c->stepY = -1;
		c->sideDistY = (m->posY - c->mapY) * c->deltaDistY;
	}
	else
	{
		c->stepY = 1;
		c->sideDistY = (c->mapY + 1 - m->posY) * c->deltaDistY;
	}
}

void ft_hit(t_w  *c )
{
	while (c->hit == 0)
	{
	if (c->sideDistX < c->sideDistY)
	{
		c->sideDistX += c->deltaDistX;
		c->mapX += c->stepX;
		c->side = 0;
	}
	else
	{
		c->sideDistY += c->deltaDistY;
		c->mapY += c->stepY;
		c->side = 1;
	}
	if (c->map.dig_map[c->mapX][c->mapY] > 0)
		c->hit = 1;
	}
}

void ft_othercalc(t_w *c, d_moves *m)
{
	if (c->side == 0)
		c->perpWallDist = (c->mapX - m->posX + (1 - c->stepX) / 2) / c->rayDirX;
	else
		c->perpWallDist = (c->mapY - m->posY + (1 - c->stepY) / 2) / c->rayDirY;
	c->lineHeight = (int)(H_WIN / c->perpWallDist);
	c->drawStart = -c->lineHeight / 2 + H_WIN / 2;
	if(c->drawStart < 0)
		c->drawStart = 0;
	c->drawEnd = c->lineHeight / 2 + H_WIN / 2;
	if(c->drawEnd >= H_WIN)
		c->drawEnd = H_WIN - 1;
}

int ft_hook_wolf(d_win *dw, t_w *c, d_moves *m, SDL_Event *e)
{
	m += 0;
	c += 0;
	SDL_Surface *new_surf;
		SDL_Surface *tmp;
		if(e->type == SDL_QUIT)
			return (0);
		else if(e->type == SDL_KEYDOWN)
		{
		new_surf = SDL_CreateRGBSurface(0, W_WIN, H_WIN, 32, \
		0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
		tmp = dw->surf;
		dw->surf = new_surf;
		SDL_FreeSurface(tmp);
		}
	return (1);
}

void	ft_config_data(t_w *c, d_moves	*m, int x)
{
c->cameraX = 2 * x / (double)(W_WIN) - 1;
c->rayDirX = m->dirX + m->planeX * c->cameraX;
c->rayDirY = m->dirY + m->planeY * c->cameraX;
c->mapX = (int)m->posX;
c->mapY = (int)m->posY;
c->deltaDistX = fabs(1 / c->rayDirX);
c->deltaDistY = fabs(1 / c->rayDirY);
c->hit = 0;
c->side = 2;
}

void ft_kill(d_win *dw)
{
if (dw->texture)
SDL_DestroyTexture(dw->texture);
if (dw->render)
SDL_DestroyRenderer(dw->render);
if (dw->sdl_win)
SDL_DestroyWindow(dw->sdl_win);
if (dw->surf)
SDL_FreeSurface(dw->surf);
SDL_Quit();
}

color_rgb ft_colors(t_w *c)
{
	color_rgb   color;
	if(c->side == 0 && c->rayDirX > 0)
	color = color_get(0,255,0,255);
	else if(c->side == 0 && c->rayDirX < 0)
	color = color_get(0,0,255,255);
	else if(c->side == 1 && c->rayDirY > 0)
	color = color_get(255,0,0,255);
	else
	color = color_get(255,254,0,255);
	return (color);
}

int ft_engine(t_w *c)
{
	SDL_Surface *new_surf;
	SDL_Surface *tmp;
	d_win		dw;
	d_moves		m;
	int x;
	SDL_Event e;
	ft_config_moves(&m, c);
    ft_screen(&dw);
	while(1)
    {
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				break ;
			else if (e.type == SDL_KEYDOWN)
			{
			new_surf = SDL_CreateRGBSurface(0, W_WIN, H_WIN, 32, \
                0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
			tmp = dw.surf;
			dw.surf = new_surf;
			SDL_FreeSurface(tmp);
			if(!ft_ui(&e, &m, c))
				break ;
			}
		}
        x = -1;
        while(x++ < W_WIN)
        {
			ft_config_data(c, &m, x);
			ft_side(c, &m);
			ft_hit(c);
			ft_othercalc(c, &m);
			ft_vert_ln(x, c, ft_colors(c), &dw);
    	}
		//c->datas_win = &dw;
		ft_redraw(&dw);
	}
	//ft_kill(&dw);
    return (1);
}