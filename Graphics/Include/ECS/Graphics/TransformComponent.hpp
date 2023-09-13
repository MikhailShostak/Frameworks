#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT TransformComponent
    : public ECS::EntityComponent
{
    using This = TransformComponent;
    using Super = ECS::EntityComponent;
    Graphics::Transform Transform = {};
    TransformComponent();

    template<typename T>
    void Serialize(T &&data)
    {
        data["Transform"] & Transform;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
