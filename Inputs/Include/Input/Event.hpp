#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT Event
{
    using This = Event;
    Graphics::Window* Window {};
    Float4 Value {};
    bool Pressed {};

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual Graphics::Scene &/*GetScene*/ GetScene() const;

    void Initialize()
    {
    }
};
}
