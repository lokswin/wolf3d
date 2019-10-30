/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:25:55 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:06:30 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	i = 0;
	if ((s != NULL) && (f != NULL))
	{
		if (!(res = (char*)malloc(ft_strlen(s) + 1)))
			return (0);
		while (s[i] != '\0')
		{
			res[i] = f((unsigned int)i, s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
