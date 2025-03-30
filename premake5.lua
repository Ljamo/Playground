workspace "Playground"
	architecture "x64"
	startproject "Playground"
	staticruntime "on"
	runtime "Release"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["GLFW"] = "vendor/GLFW/include"
-- IncludeDir["ImGui"] = "Playground/vendor/imgui"
IncludeDir["glm"] = "vendor/glm"
IncludeDir["Vulkan"] = os.getenv("VULKAN_SDK") .. "/Include"

LibDir = {}
LibDir["Vulkan"] = os.getenv("VULKAN_SDK") .. "/Lib"
-- IncludeDir["stb_image"] = "Playground/vendor/stb_image"

include "vendor/GLFW"
include "vendor/Glad"
include "vendor/ImGui"

project "Playground"
	location "Playground"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Playground/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines 
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.Vulkan}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"%{LibDir.Vulkan}/vulkan-1.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PG_PLATFORM_WINDOWS",
			--"HZ_BUILD_DLL",
			-- "GLFW_INCLUDE_HOME",
		}

	filter "configurations:Debug"
        defines { "PG_DEBUG", "PG_ENABLE_RENDERER_OPENGL", "PG_ENABLE_RENDERER_VULKAN" }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines { "PG_RELEASE", "PG_ENABLE_RENDERER_OPENGL", "PG_ENABLE_RENDERER_VULKAN" }
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines { "PG_DIST", "PG_ENABLE_RENDERER_OPENGL", "PG_ENABLE_RENDERER_VULKAN" }
        runtime "Release"
        optimize "on"