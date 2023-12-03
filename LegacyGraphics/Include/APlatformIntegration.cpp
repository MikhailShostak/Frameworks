#include "APlatformIntegration.h"

APlatform *PlatformInstance = nullptr;

APlatform &APlatformInstance()
{
    return *PlatformInstance;
}

void SetPlatformInstance(APlatform &platform)
{
    PlatformInstance = &platform;
}
