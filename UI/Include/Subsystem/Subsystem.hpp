#pragma once

namespace UI2
{
struct PUBLIC_API_EXPORT Subsystem
    : public Graphics::RenderingSubsystem
{
    using This = Subsystem;
    using Super = Graphics::RenderingSubsystem;
    int32_t FPS {};
    int32_t Frames {};
    float Time {};
    SharedReference<UI2::View> RootView {};

    virtual ~Subsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["RootView"] & RootView;
    }
    virtual void RenderScene(Graphics::Window & Window, Graphics::Scene & Scene);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
