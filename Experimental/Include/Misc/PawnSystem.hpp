#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT PawnSystem
    : public Graphics::SceneSubsystem
{
    using This = PawnSystem;
    using Super = Graphics::SceneSubsystem;

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void OnUpdate(EScene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
