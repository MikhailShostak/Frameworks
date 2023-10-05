#pragma once

namespace Input
{
struct PUBLIC_API_EXPORT Action
{
    using This = Action;
    Array<Input::CallbackType> Handlers {};

    virtual ~Action() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual bool/*Handled*/ Trigger(const Input::Event & Event);

    void Initialize()
    {
    }
};
}
