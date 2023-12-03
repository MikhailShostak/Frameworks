#pragma once

#include <OneStudioPlatform.hpp>
#include <OneStudioProjectLibrary>

#include "OSPlatformPlugin.h"

extern const char *OSProjectPluginPackage;
extern const char *OSProjectPluginVersion;

extern Map<String, OSPlatformPlugin*> PlatformPlugins;
