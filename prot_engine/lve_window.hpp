#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace lve
{

	class LveWindow
	{
		void initWindow();

		
		std::string windowName;
		GLFWwindow *window;

		static void framebufferResizedCallback(GLFWwindow* window, int width, int heigth);

	public:
		LveWindow(int w, int h, std::string name);
		~LveWindow();

		int width, heigth;
		bool framebufferResized = false;

		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

		bool shouldClose()
		{
			
			return glfwWindowShouldClose(window);
		};
		VkExtent2D getExtent()
		{
			return { static_cast<uint32_t>(width), static_cast<uint32_t>(heigth) };
		}
		bool wasWindowResized() {return framebufferResized;}
		void resetWindowResizedFlag() { framebufferResized = false;  }

		void createWindowSurface(VkInstance inctance, VkSurfaceKHR *surface);
	};

}