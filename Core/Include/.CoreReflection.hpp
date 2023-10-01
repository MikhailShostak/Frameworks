#pragma once

namespace
{

struct CoreReflectionType
{
    CoreReflectionType()
    {
        Reflection::Add<Core::Subsystem>("Core.Subsystem");
        Reflection::Add<Core::AssetManagerSubsystem>("Core.AssetManagerSubsystem");
        Reflection::Add<Core::Application>("Core.Application");
        Reflection::Add<Core::ApplicationComponent>("Core.ApplicationComponent");
    }
} inline CoreReflection;

}
