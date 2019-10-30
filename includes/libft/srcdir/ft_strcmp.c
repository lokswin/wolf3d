/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:45:54 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:05:58 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}
