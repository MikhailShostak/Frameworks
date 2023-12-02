#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT SpawnerSubsystem
    : public Graphics::SceneSubsystem
{
    using This = SpawnerSubsystem;
    using Super = Graphics::SceneSubsystem;

    virtual ~SpawnerSubsystem() {}
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
