#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT KeyboardButtonBinding
    : public Input::ButtonBinding<Input::KeyboardButton>
{
    using This = KeyboardButtonBinding;
    using Super = Input::ButtonBinding<Input::KeyboardButton>;

    virtual ~KeyboardButtonBinding() {}
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
