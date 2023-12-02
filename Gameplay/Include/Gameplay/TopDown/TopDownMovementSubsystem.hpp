#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT TopDownMovementSubsystem
    : public Graphics::SceneSubsystem
{
    using This = TopDownMovementSubsystem;
    using Super = Graphics::SceneSubsystem;

    virtual ~TopDownMovementSubsystem() {}
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
