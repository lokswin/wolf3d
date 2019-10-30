/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:23:16 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:03:54 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cast;

	cast = b;
	while (len--)
		*cast++ = (unsigned char)c;
	return (b);
}
