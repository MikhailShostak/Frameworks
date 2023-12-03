#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT GLFWSubsystem
    : public Graphics::WindowSubsystem
{
    using This = GLFWSubsystem;
    using Super = Graphics::WindowSubsystem;
    SharedReference<Input::Subsystem> Input {};

    virtual ~GLFWSubsystem() {}
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
    }
};
}
