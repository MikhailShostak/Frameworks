#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT PawnComponent
    : public ECS::EntityComponent
{
    using This = PawnComponent;
    using Super = ECS::EntityComponent;
    Float2 InputVector {};

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
