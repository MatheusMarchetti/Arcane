#include "Core/Window.h"

#include "GLFW/glfw3.h"

#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

void Arcane::Window::InitializeGLFW()
{
	glfwInit();
}

void Arcane::Window::TerminateGLFW()
{
	glfwTerminate();
}

void Arcane::Window::PollEvents()
{
	glfwPollEvents();
}

void Arcane::Window::Create(uint32_t width, uint32_t height, const char* name)
{
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	auto window = glfwCreateWindow(width, height, name, nullptr, nullptr);
	m_WindowHandle = window;

#ifdef PLATFORM_WINDOWS
	m_NativeHandle = glfwGetWin32Window(window);
#else
#error("PLATFORM NOT SUPPORTED");
#endif // PLATFORM_WINDOWS

}

void Arcane::Window::Destroy()
{
	glfwDestroyWindow((GLFWwindow*)m_WindowHandle);
	m_NativeHandle = nullptr;
}

bool Arcane::Window::IsOpen()
{
	return !glfwWindowShouldClose((GLFWwindow*)m_WindowHandle);
}

void Arcane::Window::Show()
{
	glfwShowWindow((GLFWwindow*)m_WindowHandle);
}
