/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_glfw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:32:09 by drafe             #+#    #+#             */
/*   Updated: 2019/10/20 21:44:56 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static GLFWwindow *ft_initwindow()
**	Function to initialise window vulkan
** **************************************************************************
*/

static GLFWwindow		*ft_initwindow()
{
	GLFWwindow	*new_w;

	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	new_w = glfwCreateWindow(W, H, "Wolf3d", NULL, NULL);
	return(new_w);
}

/*
** **************************************************************************
**	VkInstance *ft_initvulkan()
**	Function to initialise vulkan
** **************************************************************************
*/

VkInstance		*ft_initvulkan()
{
	VkInstance	*inst;

	inst = ft_run_vk();
	//setupDebugCallback();
	pickphysicaldevice(inst);
	return(inst);
}

/*
** **************************************************************************
**	static void ft_mainloop(GLFWwindow *window)
**	Function to app running until either an error occurs or the window is
**	closed
** **************************************************************************
*/

static void		ft_mainloop(GLFWwindow *window)
{
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
}

/*
** **************************************************************************
**	static void ft_cleanup(GLFWwindow *window)
**	Function to clean up resources
** **************************************************************************
*/

static void		ft_cleanup(GLFWwindow *window, VkInstance *inst)
{
	vkDestroyInstance(*inst, NULL);
	glfwDestroyWindow(window);
	glfwTerminate();
}

/*
** **************************************************************************
**	void ft_run_glfw()
**	Function to initialise glfw
** **************************************************************************
*/

void			ft_run_glfw()
{
	GLFWwindow	*glfw_w;
	VkInstance	*inst;

	glfw_w = ft_initwindow();
	inst = ft_initvulkan();
	ft_mainloop(glfw_w);
	ft_cleanup(glfw_w, inst);
}

