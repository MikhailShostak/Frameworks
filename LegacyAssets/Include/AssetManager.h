#pragma once

#include <LegacyFoundation.hpp>

class PUBLIC_API_EXPORT AssetManager : public ASingleton<AssetManager>
{
public:
    Map<String, ADelegate<AVariant()>> assets;
};
