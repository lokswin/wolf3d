/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/20 21:47:07 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static GLFWwindow *ft_initwindow()
**	Function to initialise window vulkan
** **************************************************************************
*/

void					pickphysicaldevice(VkInstance	*inst)
{
	VkPhysicalDevice	physicaldevice;
	uint32_t			devicecount;
	
	devicecount = 0;
	vkEnumeratePhysicalDevices(*inst, &devicecount, NULL);
	physicaldevice = VK_NULL_HANDLE;
	if (devicecount == 0)
		ft_putstr_fd("failed to find GPUs with Vulkan support.", 2);
	
}