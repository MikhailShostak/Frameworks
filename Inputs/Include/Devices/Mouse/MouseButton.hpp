#pragma once

namespace Input
{
enum class MouseButton
{
    Undefined,
    Left,
    Right,
    Middle,
    Extra1,
    Extra2,
};
}

namespace Serialization
{
template<>
struct Serializer<InputValue, Input::MouseButton>
{
    template<typename InputValue, typename ValueType>
    static void Write(InputValue&& data, ValueType&& value)
    {
        if (data.m_Storage.IsScalar())
        {
            const auto &valueName = data.m_Storage.template as<std::string>();
            if (valueName == "Undefined") { value = Input::MouseButton::Undefined; return; }
            if (valueName == "Left") { value = Input::MouseButton::Left; return; }
            if (valueName == "Right") { value = Input::MouseButton::Right; return; }
            if (valueName == "Middle") { value = Input::MouseButton::Middle; return; }
            if (valueName == "Extra1") { value = Input::MouseButton::Extra1; return; }
            if (valueName == "Extra2") { value = Input::MouseButton::Extra2; return; }
            value = Input::MouseButton::Undefined;

        }
    }
};

template<>
struct Serializer<OutputValue, Input::MouseButton>
{
    template<typename OutputValue, typename ValueType>
    static void Write(OutputValue&& data, ValueType&& value)
    {

        switch(value)
        {
        case Input::MouseButton::Undefined: data.m_Storage = "Undefined"; return;
        case Input::MouseButton::Left: data.m_Storage = "Left"; return;
        case Input::MouseButton::Right: data.m_Storage = "Right"; return;
        case Input::MouseButton::Middle: data.m_Storage = "Middle"; return;
        case Input::MouseButton::Extra1: data.m_Storage = "Extra1"; return;
        case Input::MouseButton::Extra2: data.m_Storage = "Extra2"; return;
        }

    }
};

}
