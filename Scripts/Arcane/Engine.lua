project "Engine"
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
        IncludePath["Engine"], -- self Include
        
        IncludePath["Core"]
    }

    links
    {
        "Core"
    }

    libdirs
    {
        -- add paths for prebuilt libs
    }

    filter "platforms:SharedBuild"
        defines "ARC_ENGINE_SHARED"
        kind "SharedLib"
    
    filter "platforms:StaticBuild"
        kind "StaticLib"