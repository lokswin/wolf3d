/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:45:14 by drafe             #+#    #+#             */
/*   Updated: 2019/10/18 16:18:07 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "./libft/libft.h"
# include "keys.h"
# include "mlx.h"

# include <stdio.h>//printf remove before push
# include <math.h>
# include <pthread.h>
# include <fcntl.h>
# include <time.h>//time remove before push
# define W 800
# define H 800

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

#endif
