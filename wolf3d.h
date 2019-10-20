/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:45:14 by drafe             #+#    #+#             */
/*   Updated: 2019/10/20 21:44:21 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "./libft/libft.h"
# include "keys.h"
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
# define APP_SHORT_NAME "vulkansamples_instance"
# define W 800
# define H 800
# define GLM_FORCE_RADIANS
# define GLM_FORCE_DEPTH_ZERO_TO_ONE

/*
** **************************************************************************
**	typedef struct s_w
**	Structure for store window settings
** **************************************************************************
*/

typedef struct		s_w
{
	pthread_mutex_t lock_x;
	char			*img;
	int				threads;
	int				ln_sz;
	int				bitspp;
	int				endi;
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
}					t_w;

void				ft_run_glfw();
VkInstance			*ft_run_vk();
void				pickphysicaldevice(VkInstance *inst);

/*
include path
//${workspaceFolder}*{*}
///Users/drafe/.brew/Cellar/glfw/3.3/include/GLFW*{*}
///Users/drafe/.brew/Cellar/cglm/0.6.0/include{*}
*/
#endif
