#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT SFMLSubsystem
    : public Graphics::WindowSubsystem
{
    using This = SFMLSubsystem;
    using Super = Graphics::WindowSubsystem;
    SharedReference<Input::Subsystem> Input {};
    SFMLSubsystem();

    virtual ~SFMLSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void Load();
    virtual void Unload();
    virtual void Update();

    void Initialize()
    {
        Super::Initialize();
        {
            String data =
R"(
Graphics.SFMLRHIContext
)";
            Serialization::FromString(data, RHIContextClass);
        }
        {
            String data =
R"(
Graphics.SFMLWindow
)";
            Serialization::FromString(data, WindowClass);
        }
    }
};
}
