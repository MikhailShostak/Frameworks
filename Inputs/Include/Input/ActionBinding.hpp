#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT ActionBinding
{
    using This = ActionBinding;
    SharedReference<Input::Action> Action {};
    Array<SharedReference<Input::InputBinding>> InputBindings {};
    Float4 Value {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Action"] & Action;
        data["InputBindings"] & InputBindings;
    }

    void Initialize()
    {
    }
};
}
