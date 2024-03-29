project "glfw"
    language "C"
	location (VcxDir)

	targetdir (BinDir)
    objdir (IntDir)

	files
	{
		(DepDir.."glfw/include/GLFW/glfw3.h"),
		(DepDir.."glfw/include/GLFW/glfw3native.h"),
		(DepDir.."glfw/src/glfw_config.h"),

		(DepDir.."glfw/src/context.c"),
		(DepDir.."glfw/src/init.c"),
		(DepDir.."glfw/src/input.c"),
		(DepDir.."glfw/src/platform.c"),
		(DepDir.."glfw/src/monitor.c"),
		(DepDir.."glfw/src/vulkan.c"),
		(DepDir.."glfw/src/window.c"),

		(DepDir.."glfw/src/null_platform.h"),
		(DepDir.."glfw/src/null_joystick.h"),
		(DepDir.."glfw/src/null_init.c"),
		(DepDir.."glfw/src/null_monitor.c"),
		(DepDir.."glfw/src/null_window.c"),
		(DepDir.."glfw/src/null_joystick.c"),
	}

	filter "system:windows"
		staticruntime "On"

		files
		{
			(DepDir.."glfw/src/win32_init.c"),
			(DepDir.."glfw/src/win32_module.c"),
			(DepDir.."glfw/src/win32_joystick.c"),
			(DepDir.."glfw/src/win32_monitor.c"),
			(DepDir.."glfw/src/win32_time.c"),
			(DepDir.."glfw/src/win32_thread.c"),
			(DepDir.."glfw/src/win32_window.c"),
			(DepDir.."glfw/src/wgl_context.c"),
			(DepDir.."glfw/src/egl_context.c"),
			(DepDir.."glfw/src/osmesa_context.c"),
		}

		defines 
		{ 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "platforms:SharedBuild"
        defines "_GLFW_BUILD_DLL"
        kind "SharedLib"

    filter "platforms:StaticBuild"
        kind "StaticLib"