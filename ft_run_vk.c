/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_vk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/20 20:56:17 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static void ft_glfw_ext(VkInstanceCreateInfo *inst_info)
**	Function to check for extension support
** **************************************************************************
*/

static void					ft_glfw_print_ext(uint32_t glfwextensioncount)
{
	VkExtensionProperties	extensions[glfwextensioncount];
	uint32_t				i;
	
	i = 0;
	vkEnumerateInstanceExtensionProperties(NULL, &glfwextensioncount, extensions);
	while(i < glfwextensioncount)
	{
		ft_putstr(extensions[i].extensionName);
		ft_putstr("\n");
		i++;
	}
}

/*
** **************************************************************************
**	static void ft_glfw_ext(VkInstanceCreateInfo *inst_info)
**	Function to initialise struct glfw extensions
** **************************************************************************
*/

static void					ft_glfw_ext(VkInstanceCreateInfo *inst_info)
{
	
	uint32_t				glfwextensioncount;
	const char				**glfwextensions;

	glfwextensioncount = 0;
	glfwextensions = glfwGetRequiredInstanceExtensions(&glfwextensioncount);
	inst_info->enabledExtensionCount = glfwextensioncount;
    inst_info->ppEnabledExtensionNames = glfwextensions;
	vkEnumerateInstanceExtensionProperties(NULL, &glfwextensioncount, NULL);
	ft_putnbr(glfwextensioncount);
	ft_putstr(" Extensions supported.\n");
	ft_glfw_print_ext(glfwextensioncount);
		
}

/*
** **************************************************************************
**	static void ft_init_app_info(VkApplicationInfo *app_info
**	Function to initialise struct app_info
** **************************************************************************
*/

static void					ft_init_app_info(VkApplicationInfo *app_info)
{
	app_info->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info->pNext = NULL;
    app_info->pApplicationName = "WOLF3D";
    app_info->applicationVersion = 1;
    app_info->pEngineName = "NO ENGINE";
    app_info->engineVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info->apiVersion = VK_API_VERSION_1_0;
}

/*
** **************************************************************************
**	static void ft_init_inst_info(VkInstanceCreateInfo *inst_info, VkApplicationInfo *app_info)
**	Function to initialise struct inst_info
** **************************************************************************
*/

static void					ft_init_inst_info(VkInstanceCreateInfo \
*inst_info, VkApplicationInfo *app_info)
{
	ft_init_app_info(app_info);
	inst_info->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    inst_info->pNext = NULL;
    inst_info->flags = 0;
    inst_info->pApplicationInfo = app_info;
	ft_glfw_ext(inst_info);
    inst_info->enabledLayerCount = 0;
    inst_info->ppEnabledLayerNames = NULL;
}


/*
** **************************************************************************
**	VkInstance *ft_run_vk()
**	Function to initialise vulkan
** **************************************************************************
*/

VkInstance		*ft_run_vk()
{
  	VkInstance				inst;
	VkInstance				*ptr;
	VkInstanceCreateInfo	inst_info;
	VkApplicationInfo		app_info;
	VkResult				res;

	ft_init_inst_info(&inst_info, &app_info);
	res = vkCreateInstance(&inst_info, NULL, &inst);
    if (res == VK_ERROR_INCOMPATIBLE_DRIVER)
	{
        ft_putstr_fd("Failed to create instance! \
		Cannot find a compatible Vulkan ICD\n", 2);
        exit(-1);
    }
	else if (res)
	{
        ft_putstr_fd("Failed to create instance! \
		Unknown error.\n", 2);
        exit(-1);
    }
	ptr = &inst;
	return(ptr);
}
