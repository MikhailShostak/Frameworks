#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT RHISubsystem
    : public Core::Subsystem
{
    using This = RHISubsystem;
    using Super = Core::Subsystem;

    virtual ~RHISubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
