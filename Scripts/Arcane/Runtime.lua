project "Runtime"
    kind "ConsoleApp" -- maybe make it windowed app ?
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
        IncludePath["Runtime"], -- self Include
        
        IncludePath["Core"],
        IncludePath["Engine"],
    }

    links
    {
        "Core",
        "Engine"
    }

    libdirs
    {
        -- add paths for prebuilt libs
    }