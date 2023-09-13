#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT RenderingSubsystem
    : public Graphics::SceneSubsystem
{
    using This = RenderingSubsystem;
    using Super = Graphics::SceneSubsystem;

    virtual ~RenderingSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void UpdateScene(Graphics::Scene & Scene);
    virtual void RenderScene(Graphics::Window & Window, Graphics::Scene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
