#pragma once
#include "Core/Logging.h"

#ifdef PLATFORM_WINDOWS
#define DEBUG_BREAK __debugbreak()
#else
#error("Platform not supported")
#endif // PLATFORM_WINDOWS

#ifdef _DEBUG

#define ARC_ASSERT(cond, msg) if( !(cond) ) { ARC_LOG("Assertion Failed: %s | %s", msg, #cond); DEBUG_BREAK; }
#define ARC_VERIFY(cond, msg) if( !(cond) ) { ARC_LOG("Verfiy Failed: %s | %s", msg, #cond); }

#elif _FAST

#define ARC_ASSERT(cond, msg) if( !(cond) ) { ARC_LOG("Assertion Failed: %s | %s", msg, #cond); }
#define ARC_VERIFY(cond, msg) if( !(cond) ) { ARC_LOG("Verfiy Failed: %s | %s", msg, #cond); }

#else

#define ARC_ASSERT(cond, msg) 
#define ARC_VERIFY(cond, msg) 

#endif // _DEBUG