BinDir = "%{wks.location}/Binaries/%{cfg.system}-%{cfg.platform}/%{cfg.buildcfg}"
IntDir = "%{wks.location}/Intermediates/%{prj.name}/%{cfg.system}-%{cfg.platform}/%{cfg.buildcfg}"

VcxDir = "%{wks.location}/Intermediates/%{prj.name}" 

SrcDir = "%{wks.location}/Source"

ArcDir = (SrcDir.."/Arcane/")
DepDir = (SrcDir.."/Dependencies/")

IncludePath = {};

IncludePath["glfw"] = (DepDir.."glfw/include")

IncludePath["Engine"] = (ArcDir.."Engine/Include")
IncludePath["Runtime"] = (ArcDir.."Runtime/Include")