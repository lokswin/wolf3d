/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/21 21:28:23 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_queue_f_i		*ft_find_queue_f_i(VkPhysicalDevice pd)
{
	t_queue_f_i			*indices;

//	int					i;
	indices = NULL;
	if (pd)
		return (0);
//	//while (i < queue_f)	
	
	return(indices);
}

void					ft_create_ld(VkPhysicalDevice pd)
{
	int					i;
//	t_queue_f_i			indices;
	i = 0;
	if (pd)
		i = 0;
//	indices = ft_find_queue_f_i(pd);
}

/*
** **************************************************************************
**	VkPhysicalDevice *ft_pick_pd(VkInstance inst)
**	Function to initialise window vulkan
** **************************************************************************
*/

VkPhysicalDevice		*ft_pick_pd(VkInstance inst)
{
	VkPhysicalDevice	pd;
	VkPhysicalDevice	*ptr;
	uint32_t			device_count;
	
	device_count = 0;
	pd = VK_NULL_HANDLE;
	vkEnumeratePhysicalDevices(inst, &device_count, NULL);
	if (device_count == 0)
		ft_putstr_fd("failed to find GPUs with Vulkan support.", 2);
	ptr = &pd;
	return(ptr);
}