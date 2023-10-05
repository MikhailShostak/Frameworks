#pragma once

namespace Input
{
template<typename ButtonType>
struct PUBLIC_API_EXPORT ButtonBinding
    : public Input::InputBinding
{
    using This = ButtonBinding;
    using Super = Input::InputBinding;
    ButtonType Button {};
    float Scale { 1.0f };
    Int4 Swizzle { 0, 1, 2, 3 };
    bool Pressed {};
    bool Handled {};

    virtual ~ButtonBinding() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Button"] & Button;
        data["Scale"] & Scale;
        data["Swizzle"] & Swizzle;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
