#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT SceneSubsystem
    : public Core::Subsystem
{
    using This = SceneSubsystem;
    using Super = Core::Subsystem;

    virtual ~SceneSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void Update();
    virtual void UpdateScene(Graphics::Scene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
