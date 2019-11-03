/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:45:14 by drafe             #+#    #+#             */
/*   Updated: 2019/11/03 18:52:15 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft.h"
# include "keys.h"
# include "constants.h"

# include <SDL2/SDL.h>
# include <math.h>
# include <pthread.h>
# include <fcntl.h>
# include <stdio.h>//printf remove before push
# include <time.h>//time remove before push
# define deg_to_rad(degs) ((degs) * M_PI / 180.0)
# define rad_to_deg(rads) ((rads) * 180.0 / M_PI)

/*
** **************************************************************************
**	typedef struct s_cross
**	Structure for store one ray intersection
** **************************************************************************
*/

typedef struct		s_cross
{
	int				x;
	int				y;
}					t_cross;

/*
** **************************************************************************
**	typedef struct s_map
**	Structure for store map
** **************************************************************************
*/

typedef struct		s_map
{
	int				**dig_map;
	int				size;
	double			pl;
	double			p_x;
	double			p_y;
	double			p_dir_x;
	double			p_dir_y;
	double			p_plane_x;
	double			p_plane_y;
}					t_map;

/*
** **************************************************************************
**	typedef struct s_w
**	Structure for store window settings
** **************************************************************************
*/

typedef struct		s_w
{
	SDL_Window		*sdl_win;

	pthread_mutex_t lock_x;
	t_map			map;
	t_cross			hor_point;
	t_cross			vert_point;
	int				player_x;
	int 			player_y;
	int				player_speed;
	int				player_height;
	int				player_dist;
	int				player_angle;
	int				px;
	int				py;
	char			*img;
	int				threads;
	int				ln_sz;
	int				bitspp;
	int				endi;
	int				ray_angle;
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	//////////////////////////
	double		cameraX; //x-coordinate in camera space
	double 		rayDirX;
	double 		rayDirY;
	double 	sideDistX;//length of ray from current position to next x or y-side
	double 	sideDistY;
	int 	mapX;//which box of the map we're in
	int 	mapY;
	double	deltaDistX;//length of ray from one x or y-side to next x or y-side
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;//what direction to step in x or y-direction (either +1 or -1)
	int		stepY;
	int		 hit; //was there a wall hit?
	int		side; //was a NorthSouth or a EstWest wall hit?
	int		lineHeight;//Calculate height of line to draw on screen
	int		drawStart;//calculate lowest and highest pixel to fill in current stripe
	int		drawEnd;
	SDL_PixelFormat *pix;

}					t_w;
typedef struct data_win
{
SDL_Window		*sdl_win;
SDL_Surface		*surf;
SDL_Renderer	*render;
SDL_Texture* 	texture;
int 			fullscreen;
SDL_PixelFormat *pix;
}		d_win;

typedef struct data_moves
{
int **wmap;
double posX;
double posY;
double planeX;
double planeY;
double dirX;
double dirY;

}	d_moves;

typedef struct ColorRGBA
{
int r;
int g;
int b;
int a;

}			color_rgb;


int					ft_map_chk(int fd, t_w *w);
void				ft_put_map_man();

void				ft_show_map(t_map *map);
int					ft_save_line(char *line, int *ptr, int size);

void				ft_sdl_error();
void				ft_sdl_run(t_w *w);

void				ft_ray(t_w *w);
void				ft_init_rect(SDL_Rect *rect);
void				ft_draw(t_w *w);


void			ft_sdl_hook();


/*
** --------------ft_ui.c--------------
*/

int			ft_ui(SDL_Event	*e, d_moves *m, t_w *w);
/*
** --------------screen.c--------------
*/

void		screen(struct data_win *dw);

/*
** -------------config.c--------------
*/
void		config_moves(d_moves *m, t_w *w);
void		config_win(struct data_win *dw);


/*
** --------------draw.c--------------
*/
color_rgb	color_get(int r, int g, int b, int a);
int			verLine(int x, t_w *c, struct ColorRGBA color, SDL_Surface	*surf);//draw vertical lines
void		redraw(d_win *w);//update, redraw
void		cls(d_win *w);//clear, NOT WORKING, need to check how to correct clear window



int			ft_engine(t_w *w);

/*
include path
//${workspaceFolder}*{*}
///Users/drafe/.brew/Cellar/glfw/3.3/include/GLFW*{*}
///Users/drafe/.brew/Cellar/cglm/0.6.0/include{*}
*/
#endif
