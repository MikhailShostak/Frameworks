#pragma once

#include <LegacyFoundation.hpp>

#include "Graphics/AGraphicsEvents.h"

class AMesh;
namespace Core
{
    class Material;
}
class AParticleEmitter;

class AOpenGLGraphicsContext : public AObject
{
    AObject &owner;
public:
    AOpenGLGraphicsContext(AObject &owner);
};
