#pragma once

#include <LegacyFoundation.hpp>

#include "AGraphicsEvents.h"

class AMesh;
namespace Core
{
    class Material;
}
class AParticleEmitter;

class PUBLIC_API_EXPORT AOpenGLGraphicsContext : public AObject
{
    AObject &owner;
public:
    AOpenGLGraphicsContext(AObject &owner);
};
