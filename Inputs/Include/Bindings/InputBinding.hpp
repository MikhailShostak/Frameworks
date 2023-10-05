#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT InputBinding
{
    using This = InputBinding;

    virtual ~InputBinding() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
}
