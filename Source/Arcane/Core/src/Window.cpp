#include "Core/Window.h"

#ifdef PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#else
#error("Platform not supported")
#endif // PLATFORM_WINDOWS

#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"

namespace Utils
{
	void* GetNativeWindow(GLFWwindow* window)
	{

#ifdef PLATFORM_WINDOWS
		return glfwGetWin32Window(window);
#else

#error("PLATFORM NOT SUPPORTED");
		return nullptr;
#endif // PLATFORM_WINDOWS

	}
}

void Arcane::WindowManager::Intialize()
{
	glfwInit();
}

void Arcane::WindowManager::Terminate()
{
	glfwTerminate();
}

void Arcane::WindowManager::PollEvents()
{
	glfwPollEvents();
}

void Arcane::WindowManager::Create(Window* pWindow)
{
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	auto window = glfwCreateWindow(pWindow->width, pWindow->height, pWindow->name, nullptr, nullptr);
	pWindow->nativeHandle = Utils::GetNativeWindow(window);
	pWindow->windowHandle = window;

	glfwSetWindowUserPointer(window, pWindow);

	glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
		{
			auto& data = *(Window*)glfwGetWindowUserPointer(window);
			if (data.callbacks.closeFnc) data.callbacks.closeFnc();
		});

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
		{
			auto& data = *(Window*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;
			if (data.callbacks.resizeFnc) data.callbacks.resizeFnc(width, height);
		});

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			auto& data = *(Window*)glfwGetWindowUserPointer(window);
			if(data.callbacks.keyFnc) data.callbacks.keyFnc(key, action, mods);
		});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
		{
			auto& data = *(Window*)glfwGetWindowUserPointer(window);
			if(data.callbacks.mouseFnc) data.callbacks.mouseFnc(button, action, mods);
		});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos)
		{
			auto& data = *(Window*)glfwGetWindowUserPointer(window);
			if (data.callbacks.cursorFnc) data.callbacks.cursorFnc(xPos, yPos);
		});

	glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			auto& data = *(Window*)glfwGetWindowUserPointer(window);
			if (data.callbacks.scrollFnc) data.callbacks.scrollFnc(xOffset, yOffset);
		});

	glfwSetDropCallback(window, [](GLFWwindow* window, int path_count, const char* paths[])
		{
			auto& data = *(Window*)glfwGetWindowUserPointer(window);
			if (data.callbacks.dropFnc)
				data.callbacks.dropFnc(path_count, paths);
		});
}

void Arcane::WindowManager::Destroy(Window* pWindow)
{
	glfwDestroyWindow((GLFWwindow*)pWindow->windowHandle);
}

bool Arcane::WindowManager::IsOpen(Window* pWindow)
{
	return !glfwWindowShouldClose((GLFWwindow*)pWindow->windowHandle);
}

void Arcane::WindowManager::Show(Window* pWindow)
{
	glfwShowWindow((GLFWwindow*)pWindow->windowHandle);
}
