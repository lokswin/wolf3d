/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/29 19:13:12 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

//EXAMPLE OF MAP,each number is a different color
int worldMap[24][24]=
{
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,5,0,0,0,0,5,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,2,2,5,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,0,2,5,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/*
** **************************************************************************
**	static void ft_read(char *source_f)
**	Function to get user map
** **************************************************************************
*/

static void					ft_read(int fd, t_w *new_w)
{
	int		res;
	int		i;

	if (!ft_map_chk(fd, new_w))
	{
		ft_put_map_man();
		ft_putstr_fd("Map error.\n", 2);
		exit(1);
	}
	i = 0;
	res = 0;
}

/*
** **************************************************************************
**	static int ft_open(char *source_f)
**	Function to open map
** **************************************************************************
*/

static int					ft_open(char *source_f)
{
	int	fd;

	if ((fd = open(source_f, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Open error. Usage: sh ./run.sh\n", 2);
		exit(1);
	}
	return (fd);
}


/*
** **************************************************************************
**	int main(int argc, char **argv)
**	Function to get user map
** **************************************************************************
*/

int							main(int argc, char **argv)
{
	clock_t			t;
	double			time_taken;
	t_w				new_w;
	int				fd;
	d_moves m;
	d_win dw;
	t_w c;
	SDL_Event event = { 0 };

	//t = clock();
	if ((argc != 2) || (argv[1] == NULL))
	{
		ft_putstr_fd("Usage: sh ./run.sh\n", 2);
		exit(1);
	}
	fd = ft_open(argv[1]);
	ft_read(fd, &new_w);

	printf("|{after reading map we get mapsize=%d}|\n", new_w.map.size);
	//ft_sdl_run(&new_w);
	//ft_ray(&new_w);
	//t = clock() - t;
	//time_taken = (double)t / CLOCKS_PER_SEC;
	//printf("\ntime_taken = %f\n", time_taken);
	//------------------------------------------------------------
	config_moves(&m);
	config_win(&dw);
	SDL_Event e;
	screen(&dw);//esta funcion la remplazamos creando una ventana
	c.pix = dw.pix;
	while(1)//hasta que no se aplaste esc
	{
		if (SDL_PollEvent(&e)){if (e.type == SDL_QUIT){break;}}

	for(int x = 0; x < 512; x++) {//calculate ray position and direction

	struct ColorRGBA color;   //choose wall color
	c.cameraX = 2 * x / (double) (dw.w) - 1;
	c.rayDirX = m.dirX + m.planeX * c.cameraX;
	c.rayDirY = m.dirY + m.planeY * c.cameraX;
	c.mapX = (int) m.posX;
	c.mapY = (int) m.posY;
	c.deltaDistX = fabs(1 / c.rayDirX);
	c.deltaDistY = fabs(1 / c.rayDirY);
	c.hit = 0;
	c.side = 2;
	if(c.rayDirX < 0)//calculate step and initial sideDist
	{
	c.stepX = -1;
	c.sideDistX = (m.posX - c.mapX) * c.deltaDistX;
	} else {
	c.stepX = 1;
	c.sideDistX = (c.mapX + 1.0 - m.posX) * c.deltaDistX;
	}
	if(c.rayDirY < 0) {
	c.stepY = -1;
	c.sideDistY = (m.posY - c.mapY) * c.deltaDistY;
	} else {
	c.stepY = 1;
	c.sideDistY = (c.mapY + 1.0 - m.posY) * c.deltaDistY;
	}
	while (c.hit == 0)//perform DDA
	{
	if(c.sideDistX < c.sideDistY)//jump to next map square, OR in x-direction, OR in y-direction
	{
	c.sideDistX += c.deltaDistX;
	c.mapX += c.stepX;
	c.side = 0;
	} else {
	c.sideDistY += c.deltaDistY;
	c.mapY += c.stepY;
	c.side = 1;
	}
	if(worldMap[c.mapX][c.mapY] > 0)
	c.hit = 1; //Check if ray has hit a wall
	}
	if(c.side == 0)//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
	c.perpWallDist = (c.mapX - m.posX + (1 - c.stepX) / 2) / c.rayDirX;
	else
	c.perpWallDist = (c.mapY - m.posY + (1 - c.stepY) / 2) / c.rayDirY;
	c.lineHeight = (int) (dw.h / c.perpWallDist);//Calculate height of line to draw on screen
	c.drawStart = -c.lineHeight / 2 + dw.h / 2; //calculate lowest and highest pixel to fill in current stripe
	if(c.drawStart < 0)c.drawStart = 0;
	c.drawEnd = c.lineHeight / 2 + dw.h / 2;
	if(c.drawEnd >= dw.h)
	c.drawEnd = dw.h - 1;
	if(worldMap[c.mapX][c.mapY] == 1)
	color = color_get(255, 0, 0, 255);
	else if(worldMap[c.mapX][c.mapY] == 2)
	color = color_get(0, 255, 0, 255);
	else if(worldMap[c.mapX][c.mapY] == 3)
	color = color_get(255, 255, 255, 255);
	else if(worldMap[c.mapX][c.mapY] == 4)
	color = color_get(0, 0, 255, 255);
	else
	color = color_get(255, 255, 224, 255);
	if(c.side == 1) //give x and y sides different brightness
	color = color_get(color.r / 2, color.g / 2, color.b / 2, 255);
	verLine(x, &c, color, dw.surf);//draw the pixels of the stripe as a vertical line
	//}
	redraw(&dw);
	//cls(&dw);
	if(e.type == SDL_KEYDOWN)
	ft_ui(&e, &m, worldMap);
		}
	}
}
//read map
//check map W & H
//check symbols in map file
//printf map man
//save map in struct s_map
//save struct s_map into struct s_w
//build map
//place player
//catch user input