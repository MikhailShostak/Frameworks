#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT SpriteComponent
    : public ECS::EntityComponent
{
    using This = SpriteComponent;
    using Super = ECS::EntityComponent;
    ECS::SpriteMaterial Material {};
    Float2 Size {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Material"] & Material;
        data["Size"] & Size;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
