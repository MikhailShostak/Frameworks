#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT CameraComponent
    : public ECS::EntityComponent
{
    using This = CameraComponent;
    using Super = ECS::EntityComponent;
    Graphics::Camera Camera = {};

    virtual ~CameraComponent() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Camera"] & Camera;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
