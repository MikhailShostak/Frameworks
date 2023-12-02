#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT ProjectileSubsystem
    : public Graphics::SceneSubsystem
{
    using This = ProjectileSubsystem;
    using Super = Graphics::SceneSubsystem;

    virtual ~ProjectileSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void UpdateScene(Graphics::Scene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
