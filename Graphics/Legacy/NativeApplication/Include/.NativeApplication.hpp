#pragma once

struct NativeWindowHandleData;

#define ENGINE_DLL 0
#define VULKAN_SUPPORTED 1

#if BOOST_OS_MACOS
#define GLFW_EXPOSE_NATIVE_COCOA 1
#elif BOOST_OS_LINUX
#define PLATFORM_LINUX 1
#define GLFW_EXPOSE_NATIVE_X11 1
#elif BOOST_OS_ANDROID
#define PLATFORM_ANDROID 1
#elif BOOST_OS_WINDOWS
#define PLATFORM_WIN32 1
#define GLFW_EXPOSE_NATIVE_WIN32 1
#endif

#include "NativeWindowHandle.hpp"
#include "WindowComponent.hpp"
