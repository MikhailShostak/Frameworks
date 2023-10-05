#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT SFMLRHIContext
    : public Graphics::RHIContext
{
    using This = SFMLRHIContext;
    using Super = Graphics::RHIContext;

    virtual ~SFMLRHIContext() {}
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
