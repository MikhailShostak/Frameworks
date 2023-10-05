#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT AxisBinding
    : public Input::InputBinding
{
    using This = AxisBinding;
    using Super = Input::InputBinding;
    uint8_t Axis {};
    float Scale { 1.0f };
    Int4 Swizzle { 0, 1, 2, 3 };
    bool Handled {};

    virtual ~AxisBinding() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Axis"] & Axis;
        data["Scale"] & Scale;
        data["Swizzle"] & Swizzle;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
