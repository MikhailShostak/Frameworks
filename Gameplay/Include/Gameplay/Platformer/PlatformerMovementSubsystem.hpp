#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT PlatformerMovementSubsystem
    : public Graphics::SceneSubsystem
{
    using This = PlatformerMovementSubsystem;
    using Super = Graphics::SceneSubsystem;

    virtual ~PlatformerMovementSubsystem() {}
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
