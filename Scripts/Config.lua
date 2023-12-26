filter "system:windows"
    defines "PLATFORM_WINDOWS"
    systemversion "latest"

filter "system:linux"
    defines "PLATFORM_LINUX"

filter "platforms:SharedBuild"
    defines "BUILD_SHARED"

filter "platforms:StaticBuild"
    defines "BUILD_STATIC"

filter "configurations:Debug"
    defines "_DEBUG"
    optimize "Off"
    symbols "On"
    
filter "configurations:Fast"
    defines { "NDEBUG", "_FAST" }
    optimize "Debug"
    symbols "On"

filter "configurations:Profile"
    defines { "NDEBUG", "_PROFILE" }
    optimize "Full"
    symbols "Off"

filter "configurations:Release"
    defines "NDEBUG"
    optimize "Full"
    symbols "Off"