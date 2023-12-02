#pragma once

namespace Gameplay
{
struct PUBLIC_API_EXPORT AbilitySubsystem
    : public Graphics::SceneSubsystem
{
    using This = AbilitySubsystem;
    using Super = Graphics::SceneSubsystem;

    virtual ~AbilitySubsystem() {}
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
