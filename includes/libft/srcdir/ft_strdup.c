/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:37:46 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:06:06 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

char			*ft_strdup(const char *s1)
{
	char		*dup;
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	len = ft_strlen(s1) + 1;
	if (!(dup = (char*)malloc(sizeof(char) * len)))
		return (0);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
