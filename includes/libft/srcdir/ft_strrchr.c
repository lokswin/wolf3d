/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 21:07:59 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:06:49 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

char			*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*res;

	i = ft_strlen(s);
	if (!s)
		return (0);
	if (c == '\0')
		return ((char*)s + i);
	res = ft_strchr(s, '\0');
	while ((*res != c) && (i != 0))
	{
		res--;
		if (*res == c)
			return (res);
		i--;
	}
	return (0);
}
