/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:45:14 by drafe             #+#    #+#             */
/*   Updated: 2019/11/01 18:35:22 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/incdir/libft.h"
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
	int				pl;
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
	SDL_Surface		*w_surf;
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
}					t_w;

int					ft_map_chk(int fd, t_w *w);


void				ft_put_map_man();
void				ft_show_map(t_map *map);
void				ft_save_line(char *line, int *ptr, int size);

void				ft_sdl_error();
void				ft_sdl_run(t_w *w);

void				ft_ray(t_w *w);
void				ft_init_rect(SDL_Rect *rect);
void				ft_draw(t_w *w);

int					ft_ui(t_w *w, SDL_Event	*e);

/*
include path
//${workspaceFolder}*{*}
///Users/drafe/.brew/Cellar/glfw/3.3/include/GLFW*{*}
///Users/drafe/.brew/Cellar/cglm/0.6.0/include{*}
*/
#endif
