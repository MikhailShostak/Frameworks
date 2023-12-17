#pragma once

#include "AnimationSubsystem.hpp"

namespace
{

struct AnimationsReflectionType
{
    AnimationsReflectionType()
    {
        Reflection::Add<Animations::Subsystem>("Animations.Subsystem");
    }
} inline AnimationsReflection;

}
