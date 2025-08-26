#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace lve
{

	class LveWindow
	{
		void initWindow();

		const int width, heigth;

		std::string windowName;
		GLFWwindow *window;

	public:
		LveWindow(int w, int h, std::string name);
		~LveWindow();

		bool shouldClose()
		{
			return glfwWindowShouldClose(window);
		};

		void createWindowSurface(VkInstance inctance, VkSurfaceKHR *surface);
	};

}