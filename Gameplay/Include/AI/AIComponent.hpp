#pragma once

namespace AI
{
struct PUBLIC_API_EXPORT AIComponent
    : public ECS::EntityComponent
{
    using This = AIComponent;
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
