/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:49:12 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:05:10 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	if (!dst && !src)
		return (0);
	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	if (src < dst)
	{
		cast_dst += len;
		cast_src += len;
		while (len--)
			*--cast_dst = *--cast_src;
	}
	else
		while (len--)
			*cast_dst++ = *cast_src++;
	return (dst);
}
