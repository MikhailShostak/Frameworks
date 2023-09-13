#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT WindowSubsystem
    : public Core::Subsystem
{
    using This = WindowSubsystem;
    using Super = Core::Subsystem;
    Array<SharedReference<Graphics::Window>> Windows {};
    ClassReference<Graphics::Window> WindowClass {};
    ClassReference<Graphics::RHIContext> RHIContextClass {};

    virtual ~WindowSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual SharedReference<Graphics::Window>/*Window*/ Create();

    void Initialize()
    {
        Super::Initialize();
    }
};
}
