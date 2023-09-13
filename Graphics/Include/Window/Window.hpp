#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT Window
{
    using This = Window;
    SharedReference<Graphics::Scene> Scene {};
    String Title {};
    Int2 Position {};
    Int2 Size {};
    Graphics::WindowMode WindowMode {};
    Int2 MousePosition {};
    DateTime::Counter<DateTime::HighResolution::Clock> FrameCounter {};
    DateTime::SecondRatio DeltaTime {};
    UniqueReference<Graphics::RHIContext> RHIContext {};

    virtual ~Window() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Scene"] & Scene;
        data["Title"] & Title;
        data["Position"] & Position;
        data["Size"] & Size;
        data["WindowMode"] & WindowMode;
    }
    virtual void Load();
    virtual void Unload();
    virtual void Update();

    void Initialize()
    {
    }
};
}
