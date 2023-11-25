#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT MovementSystem
    : public Graphics::SceneSubsystem
{
    using This = MovementSystem;
    using Super = Graphics::SceneSubsystem;

    template<typename T>
    void Serialize(T &&data)
    {
    }
    //virtual void OnUpdate(EScene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
