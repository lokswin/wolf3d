/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:45:14 by drafe             #+#    #+#             */
/*   Updated: 2019/10/24 21:25:24 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "./libft/libft.h"
# include "keys.h"
# include "constants.h"
# include "mlx.h"

# include <stdio.h>//printf remove before push
# include <vulkan/vulkan.h>///usr/include
# include <math.h>
# include <pthread.h>
# include <fcntl.h>
# include <time.h>//time remove before push
# include <GLFW/glfw3.h>
# include <cglm/cglm.h>
# include <cglm/call.h>
# include <cglm/vec4.h>
# include <cglm/mat4.h>
# define deg_to_rad(degs) ((degs) * M_PI / 180.0)
# define rad_to_deg(rads) ((rads) * 180.0 / M_PI)

/*
** **************************************************************************
**	typedef struct s_map
**	Structure for store map
** **************************************************************************
*/

typedef struct		s_map
{
	int				size;
}					t_map;

/*
** **************************************************************************
**	typedef struct s_w
**	Structure for store window settings
** **************************************************************************
*/

typedef struct		s_w
{
	pthread_mutex_t lock_x;
	t_map			map;
	char			*img;
	int				threads;
	int				ln_sz;
	int				bitspp;
	int				endi;
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
}					t_w;

typedef struct		s_queue_f_i
{
	uint32_t		graphic_family;
		
}					t_queue_f_i;

void				ft_run_glfw();

VkInstance			*ft_run_vk();
VkPhysicalDevice	*ft_pick_pd(VkInstance inst);

void				ft_create_ld(VkPhysicalDevice pd);

t_queue_f_i			*ft_find_queue_f_i(VkPhysicalDevice pd);

int					ft_map_chk(int fd, t_w *w);
void				ft_put_map_man();

void				ft_draw(t_w *w);

/*
include path
//${workspaceFolder}*{*}
///Users/drafe/.brew/Cellar/glfw/3.3/include/GLFW*{*}
///Users/drafe/.brew/Cellar/cglm/0.6.0/include{*}
*/
#endif
