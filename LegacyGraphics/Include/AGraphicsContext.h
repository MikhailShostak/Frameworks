#pragma once

#include <LegacyFoundation.hpp>

#include "APlatformIntegration.h"

#include "AMesh.h"
#include "AParticleEmitter.h"

class AWindow;

struct PUBLIC_API_EXPORT AGraphicsSettings
{
    Math::IntegerRectangle viewPort;
};

class AWindow;
class APlatformGraphicsContext;

#include "ACamera.h"
#include "AGraphicsEvents.h"
#include "AMaterial.h"

class PUBLIC_API_EXPORT AGraphicsContext final : public AObject
{
    AGraphicsSettings settings;
    UniqueReference<AObject> platformGraphicsContext;
public:

    AGraphicsContext():
        platformGraphicsContext(APlatformInstance().createGraphicsContext(*this))
    {

    }

    const AGraphicsSettings &getGraphicsSettings() const
    {
        return settings;
    }

    void setViewPort(const Math::IntegerRectangle &viewPort)
    {
        settings.viewPort = viewPort;
    }
};