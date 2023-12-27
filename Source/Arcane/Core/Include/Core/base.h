#pragma once

#ifdef BUILD_SHARED

#ifdef PLATFORM_WINDOWS

#define ARC_EXPORT __declspec(dllexport)
#define ARC_IMPORT __declspec(dllimport)

#else

#error("Platform not supported")

#endif // PLATFORM_WINDOWS

#else

#define ARC_EXPORT 
#define ARC_IMPORT

#endif // BUILD_SHARED

#include "Core/utl.h"