#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT SFMLRHISubsystem
    : public Graphics::RHISubsystem
{
    using This = SFMLRHISubsystem;
    using Super = Graphics::RHISubsystem;

    virtual ~SFMLRHISubsystem() {}
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
