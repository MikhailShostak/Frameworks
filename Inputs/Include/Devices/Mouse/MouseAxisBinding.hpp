#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT MouseAxisBinding
    : public Input::AxisBinding
{
    using This = MouseAxisBinding;
    using Super = Input::AxisBinding;

    virtual ~MouseAxisBinding() {}
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
