/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:00:39 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:05:01 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *cast1;
	const unsigned char *cast2;
	size_t				i;

	if (n <= 0)
		return (0);
	i = 0;
	cast1 = s1;
	cast2 = s2;
	while (i < n - 1)
	{
		if (*cast1 != *cast2)
			break ;
		i++;
		cast1++;
		cast2++;
	}
	return (*cast1 - *cast2);
}
