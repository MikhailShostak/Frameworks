#pragma once

namespace Graphics
{
enum class WindowMode
{
    Windowed,
    Fullscreen,
};
}

namespace Serialization
{
template<>
struct Serializer<InputValue, Graphics::WindowMode>
{
    template<typename InputValue, typename ValueType>
    static void Write(InputValue&& data, ValueType&& value)
    {
        if (data.m_Storage.IsScalar())
        {
            const auto &valueName = data.m_Storage.template as<std::string>();
            if (valueName == "Windowed") { value = Graphics::WindowMode::Windowed; return; }
            if (valueName == "Fullscreen") { value = Graphics::WindowMode::Fullscreen; return; }
            value = Graphics::WindowMode::Windowed;

        }
    }
};

template<>
struct Serializer<OutputValue, Graphics::WindowMode>
{
    template<typename OutputValue, typename ValueType>
    static void Write(OutputValue&& data, ValueType&& value)
    {

        switch(value)
        {
        case Graphics::WindowMode::Windowed: data.m_Storage = "Windowed"; return;
        case Graphics::WindowMode::Fullscreen: data.m_Storage = "Fullscreen"; return;
        }

    }
};

}
