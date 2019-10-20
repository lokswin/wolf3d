/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/19 16:08:00 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	void ft_new_win(t_w *w)
**	Function to initialize window and image
** **************************************************************************
*/

void			ft_new_win(t_w *w)
{
	char		*head;

	head = ft_strjoin("Fractol - ", ft_w_layout(w));
	w->threads = 16;
	w->win_p = mlx_new_window(w->mlx_p, W, H, head);
	ft_strdel(&head);
	w->img_p = mlx_new_image(w->mlx_p, W, H);
	ft_ui();
	if (!w->mlx_p || !w->win_p || !w->img_p)
	{
		ft_putstr_fd("mlx error", 2);
		exit(1);
	}
	w->img = mlx_get_data_addr(w->img_p, \
	&w->bitspp, &w->ln_sz, &w->endi);
}
