/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 18:05:38 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:04:30 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (del != NULL)
	{
		if ((*alst)->next)
			ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}
