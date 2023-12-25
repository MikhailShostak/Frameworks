#pragma once

#include <OneStudioPlatform.hpp>
#include <LegacyExperimental.hpp>

class CGPrivatePlugin : public OSPlugin
{
public:
    void load(const Map<String, OSPluginContext *> &dependentPlugins) override;
};
