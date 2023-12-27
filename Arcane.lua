include "Scripts/Path.lua"

workspace "Arcane"
    architecture "x86_64"
    
    configurations 
    {
        "Debug", "Fast", "Profile", "Release"
    }

    platforms 
    {
        "SharedBuild", "StaticBuild"
    }

    
    include "Scripts/Config.lua"

    group "Dependencies"
        include "Scripts/Dependencies/glfw.lua"
    group ""

    group "Arcane"
        include "Scripts/Arcane/Core.lua"
        include "Scripts/Arcane/Engine.lua"
    group ""

    include "Scripts/Arcane/Runtime.lua"