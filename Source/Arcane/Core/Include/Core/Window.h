#pragma once
#include "Core/base.h"

#ifdef ARC_CORE_SHARED
#define ARC_CORE_API ARC_EXPORT
#else
#define ARC_CORE_API ARC_IMPORT
#endif

namespace Arcane
{
	class ARC_CORE_API Window
	{
	public:
		Window() = default;
		~Window() = default;

		static void InitializeGLFW();
		static void TerminateGLFW();

		static void PollEvents();

		void Create(uint32_t width, uint32_t height, const char* name);
		void Destroy();
		
		bool IsOpen();
		void Show();
	private:
		uint32_t m_Width, m_Height;
		void* m_WindowHandle;
		void* m_NativeHandle;
	};
}