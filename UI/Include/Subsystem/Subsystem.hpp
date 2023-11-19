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
    bool FontsDirty {};

    virtual ~Subsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["RootView"] & RootView;
    }
    virtual void PreUpdate(Graphics::Window & Window, Graphics::Scene & Scene);
    virtual void RenderScene(Graphics::Window & Window, Graphics::Scene & Scene);
    virtual void PushUIFont();
    virtual void PushMonospacedFont();
    virtual void PopFont();
    virtual void LoadFont(const System::Path & Path, fpixel_t Size, ImFontConfig* Config, const uint16_t* GlyphRange, const std::function<void(ImFont*)> & Callback);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
