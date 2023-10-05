#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT GamepadAxisBinding
    : public Input::AxisBinding
{
    using This = GamepadAxisBinding;
    using Super = Input::AxisBinding;

    virtual ~GamepadAxisBinding() {}
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
