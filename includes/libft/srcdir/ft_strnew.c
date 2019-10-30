/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:39:49 by drafe             #+#    #+#             */
/*   Updated: 2019/10/30 14:06:44 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incdir/libft.h"

char		*ft_strnew(size_t size)
{
	char	*res;

	if (!(res = (char*)ft_memalloc(sizeof(char) * size + 1)))
		return (0);
	res[size] = '\0';
	return (res);
}
