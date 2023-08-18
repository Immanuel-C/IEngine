workspace "IEngine"
    configurations {"Debug", "Release"}
    architecture "x86_64"

    print ("Make sure to set the vulkan sdk path!")

    vulkanSdk = os.getenv("VULKAN_SDK");

    function defaultBuildCfg()
        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"
            runtime "Debug"
            optimize "Debug"

        filter "configurations:Release"
            defines { "NDEBUG" }
            symbols "Off"
            runtime "Release"
            optimize "Speed"
    end

    function defaultBuildLocation()
        targetdir ("bin/TestApp/%{cfg.buildcfg}")
        objdir ("bin-int/%{prj.name}/%{cfg.buildcfg}")
    end

    startproject "TestApp"

    project "TestApp"
        location "test"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"

        files {
            "%{prj.location}/**.cpp",
            "%{prj.location}/**.h",
        }

        includedirs {
            "deps/IWindow/src",
            "deps/imgui/",
            "deps/ILog/",
            "src/",
            vulkanSdk .. "/Include"
        }

        links { "IEngine", "ILog", "IWindow" }

        defines {
            "IENGINE_DLL",
            "IWINDOW_DLL",
            "ILOG_DLL",
        }

        defaultBuildLocation()
        defaultBuildCfg();

    project "ImGui"
        location "deps/imgui"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"

        files {
            "%{prj.location}/imgui.cpp", 
            "%{prj.location}/imgui.h", 
            "%{prj.location}/imgui_draw.cpp", 
            "%{prj.location}/imgui_tables.cpp",
            "%{prj.location}/imgui_widgets.cpp",
            "%{prj.location}/backends/imgui_impl_vulkan.cpp",
            "%{prj.location}/backends/imgui_impl_vulkan.h",
        }

        includedirs {
            "%{prj.location}",
            vulkanSdk .. "/Include"
        }

        defaultBuildLocation()
        defaultBuildCfg();


    project "IWindow"
        location "deps/IWindow/src"
        kind "SharedLib"
        language "C++"
        cppdialect "C++17"

        files {
            "%{prj.location}/IWindowWin32.cpp",
            "%{prj.location}/IWindowWin32Gamepad.cpp",
            "%{prj.location}/IWindowWin32Vk.cpp",
            "%{prj.location}/IWindowImGUIBackend.cpp",
            "%{prj.location}/IWindow.h",
            "%{prj.location}/IWindowCodes.h",
            "%{prj.location}/IWindowPlatform.h",
            "%{prj.location}/IWindowGamepad.h",
            "%{prj.location}/IWindowVk.h",
            "%{prj.location}/IWindowImGUIBackend.h",
        }

        includedirs {
            "deps/IWindow/src",
            "deps/imgui/",
            vulkanSdk .. "/Include"
        }

        libdirs {
            vulkanSdk .. "/Lib",
        }

        links {
            "User32",
            "vulkan-1",
            "XInput",
            "ImGui",
        }

        
        defines {
            "IWINDOW_BUILD_DLL",
            "IWINDOW_DLL",
        }

        defaultBuildLocation()
        defaultBuildCfg();

    project "ILog"
        location "deps/ILog"
        kind "SharedLib"
        language "C"
        cdialect "C17"

        files {
            "%{prj.location}/ILog.c",
            "%{prj.location}/ILog.h",
        }

        defines {
            "ILOG_BUILD_DLL",
            "ILOG_DLL",
        }

        defaultBuildLocation()
        defaultBuildCfg();

    project "IEngine"
        location "src"
        kind "SharedLib"
        language "C++"
        cppdialect "C++17"

        files {
            "%{prj.location}/**.cpp",
            "%{prj.location}/**.h",
        }

        includedirs {
            "deps/IWindow/src",
            "deps/imgui/",
            "deps/ILog/",
            "src/",
            vulkanSdk .. "/Include"
        }


        libdirs {
            vulkanSdk .. "/Lib",
        }

        links {
            "ILog", 
            "IWindow",
            "vulkan-1",
        }

        defines {
            "IENGINE_DLL",
            "IENGINE_BUILD_DLL",
        }

        defaultBuildLocation()
        defaultBuildCfg();
