project "Runtime"
    kind "ConsoleApp" -- maybe make it windowed app ?
    language "C++"
    cppdialect "C++20"
    location (ArcDir.."%{prj.name}")

    files 
    {
        (ArcDir.."%{prj.name}/Include/**.h"),
        
        (ArcDir.."%{prj.name}/src/**.h"),
        (ArcDir.."%{prj.name}/src/**.cpp"),
    }

    includedirs
    {
        IncludePath["Runtime"], -- self
        IncludePath["Engine"]
    }

    links
    {
        "Engine"
    }

    libdirs
    {
        -- add paths for prebuilt libs
    }