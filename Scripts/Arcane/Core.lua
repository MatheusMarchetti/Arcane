project "Core"
    language "C++"
    cppdialect "C++20"
    location (ArcDir.."%{prj.name}")

    targetdir (BinDir)
    objdir (IntDir)
    
    files 
    {
        (ArcDir.."%{prj.name}/Include/**.h"),
        
        (ArcDir.."%{prj.name}/src/**.h"),
        (ArcDir.."%{prj.name}/src/**.cpp"),
    }

    includedirs
    {
        IncludePath["Core"], -- self Include

        IncludePath["glfw"],
    }

    links
    {
        "glfw"
    }

    libdirs
    {
        -- add paths for prebuilt libs
    }

    filter "platforms:SharedBuild"
        defines "ARC_CORE_SHARED"
        kind "SharedLib"
    
    filter "platforms:StaticBuild"
        kind "StaticLib"