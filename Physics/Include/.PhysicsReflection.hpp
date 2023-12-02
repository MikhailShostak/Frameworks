#pragma once

#include "Physics/PhysicsSubsystem.hpp"

namespace
{

struct PhysicsReflectionType
{
    PhysicsReflectionType()
    {
        Reflection::Add<Physics2D::PhysicsComponent>("Physics2D.PhysicsComponent");
        Reflection::Add<Physics2D::TriggerVolumeComponent>("Physics.TriggerVolumeComponent");
    }
} inline PhysicsReflection;

}
