#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT Context
{
    using This = Context;
    Array<Input::ActionBinding> ActionBindings {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["ActionBindings"] & ActionBindings;
    }

    void Initialize()
    {
    }
};
}
