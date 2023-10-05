#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT MouseButtonBinding
    : public Input::ButtonBinding<Input::MouseButton>
{
    using This = MouseButtonBinding;
    using Super = Input::ButtonBinding<Input::MouseButton>;

    virtual ~MouseButtonBinding() {}
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
