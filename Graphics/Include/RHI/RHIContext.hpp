#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT RHIContext
{
    using This = RHIContext;

    virtual ~RHIContext() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
}
