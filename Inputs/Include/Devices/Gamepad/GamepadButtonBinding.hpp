#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT GamepadButtonBinding
    : public Input::ButtonBinding<Input::GamepadButton>
{
    using This = GamepadButtonBinding;
    using Super = Input::ButtonBinding<Input::GamepadButton>;

    virtual ~GamepadButtonBinding() {}
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
