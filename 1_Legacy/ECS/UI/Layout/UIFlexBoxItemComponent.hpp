#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT UIFlexBoxItemComponent
    : public ECS::EntityComponent
{
    using This = UIFlexBoxItemComponent;
    using Super = ECS::EntityComponent;
    size_t Alignment = {};

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
