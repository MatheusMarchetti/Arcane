#pragma once
#include "Core/base.h"

#include <functional>

#ifdef ARC_CORE_SHARED
#define ARC_CORE_API ARC_EXPORT
#else
#define ARC_CORE_API ARC_IMPORT
#endif

namespace Arcane
{
	// use simple function pointers ??
	struct WindowCallbacksInterface
	{
		std::function<void()> closeFnc;
		std::function<void(int, int)> resizeFnc;
		std::function<void(int, int, int)> keyFnc;
		std::function<void(int, int, int)> mouseFnc;

		std::function<void(double, double)> cursorFnc;
		std::function<void(double, double)> scrollFnc;

		std::function<void(int, const char**)> dropFnc;
	};

	struct Window
	{
		uint32_t width = 0, height = 0;
		const char* name = nullptr;

		void* windowHandle = nullptr;
		void* nativeHandle = nullptr;

		WindowCallbacksInterface callbacks;
	};

	namespace WindowManager
	{
		void ARC_CORE_API Intialize();
		void ARC_CORE_API Terminate();

		void ARC_CORE_API PollEvents();

		void ARC_CORE_API Create(Window* pWindow);
		void ARC_CORE_API Destroy(Window* pWindow);

		bool ARC_CORE_API IsOpen(Window* pWindow);
		void ARC_CORE_API Show(Window* pWindow);
	}
}