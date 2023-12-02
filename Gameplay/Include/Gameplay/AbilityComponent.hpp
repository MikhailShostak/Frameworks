#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT AbilityComponent
    : public ECS::EntityComponent
{
    using This = AbilityComponent;
    using Super = ECS::EntityComponent;

    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
