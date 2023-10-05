#pragma once

namespace Input
{
enum class DeviceType
{
    Mouse,
    Keyboard,
    Gamepad,
};
}

namespace Serialization
{
template<>
struct Serializer<InputValue, Input::DeviceType>
{
    template<typename InputValue, typename ValueType>
    static void Write(InputValue&& data, ValueType&& value)
    {
        if (data.m_Storage.IsScalar())
        {
            const auto &valueName = data.m_Storage.template as<std::string>();
            if (valueName == "Mouse") { value = Input::DeviceType::Mouse; return; }
            if (valueName == "Keyboard") { value = Input::DeviceType::Keyboard; return; }
            if (valueName == "Gamepad") { value = Input::DeviceType::Gamepad; return; }
            value = Input::DeviceType::Mouse;

        }
    }
};

template<>
struct Serializer<OutputValue, Input::DeviceType>
{
    template<typename OutputValue, typename ValueType>
    static void Write(OutputValue&& data, ValueType&& value)
    {

        switch(value)
        {
        case Input::DeviceType::Mouse: data.m_Storage = "Mouse"; return;
        case Input::DeviceType::Keyboard: data.m_Storage = "Keyboard"; return;
        case Input::DeviceType::Gamepad: data.m_Storage = "Gamepad"; return;
        }

    }
};

}
