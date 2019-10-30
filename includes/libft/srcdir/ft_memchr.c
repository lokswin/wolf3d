/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:37:20 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:04:50 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp_cast;
	size_t				i;

	i = 0;
	tmp_cast = s;
	if (n == 0)
		return (0);
	while ((*tmp_cast != (unsigned char)c))
	{
		s++;
		tmp_cast++;
		i++;
		if (i == n)
			break ;
	}
	if (i >= n)
		return (0);
	return ((unsigned char*)s);
}
