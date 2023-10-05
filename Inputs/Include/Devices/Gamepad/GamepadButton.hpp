#pragma once

namespace Input
{
enum class GamepadButton
{
    Undefined,
    DPadUp,
    DPadRight,
    DPadBottom,
    DPadLeft,
    FaceButtonUp,
    FaceButtonRight,
    FaceButtonBottom,
    FaceButtonLeft,
    R1,
    R2,
    R3,
    R4,
    L1,
    L2,
    L3,
    L4,
    Start,
    Options,
};
}

namespace Serialization
{
template<>
struct Serializer<InputValue, Input::GamepadButton>
{
    template<typename InputValue, typename ValueType>
    static void Write(InputValue&& data, ValueType&& value)
    {
        if (data.m_Storage.IsScalar())
        {
            const auto &valueName = data.m_Storage.template as<std::string>();
            if (valueName == "Undefined") { value = Input::GamepadButton::Undefined; return; }
            if (valueName == "DPadUp") { value = Input::GamepadButton::DPadUp; return; }
            if (valueName == "DPadRight") { value = Input::GamepadButton::DPadRight; return; }
            if (valueName == "DPadBottom") { value = Input::GamepadButton::DPadBottom; return; }
            if (valueName == "DPadLeft") { value = Input::GamepadButton::DPadLeft; return; }
            if (valueName == "FaceButtonUp") { value = Input::GamepadButton::FaceButtonUp; return; }
            if (valueName == "FaceButtonRight") { value = Input::GamepadButton::FaceButtonRight; return; }
            if (valueName == "FaceButtonBottom") { value = Input::GamepadButton::FaceButtonBottom; return; }
            if (valueName == "FaceButtonLeft") { value = Input::GamepadButton::FaceButtonLeft; return; }
            if (valueName == "R1") { value = Input::GamepadButton::R1; return; }
            if (valueName == "R2") { value = Input::GamepadButton::R2; return; }
            if (valueName == "R3") { value = Input::GamepadButton::R3; return; }
            if (valueName == "R4") { value = Input::GamepadButton::R4; return; }
            if (valueName == "L1") { value = Input::GamepadButton::L1; return; }
            if (valueName == "L2") { value = Input::GamepadButton::L2; return; }
            if (valueName == "L3") { value = Input::GamepadButton::L3; return; }
            if (valueName == "L4") { value = Input::GamepadButton::L4; return; }
            if (valueName == "Start") { value = Input::GamepadButton::Start; return; }
            if (valueName == "Options") { value = Input::GamepadButton::Options; return; }
            value = Input::GamepadButton::Undefined;

        }
    }
};

template<>
struct Serializer<OutputValue, Input::GamepadButton>
{
    template<typename OutputValue, typename ValueType>
    static void Write(OutputValue&& data, ValueType&& value)
    {

        switch(value)
        {
        case Input::GamepadButton::Undefined: data.m_Storage = "Undefined"; return;
        case Input::GamepadButton::DPadUp: data.m_Storage = "DPadUp"; return;
        case Input::GamepadButton::DPadRight: data.m_Storage = "DPadRight"; return;
        case Input::GamepadButton::DPadBottom: data.m_Storage = "DPadBottom"; return;
        case Input::GamepadButton::DPadLeft: data.m_Storage = "DPadLeft"; return;
        case Input::GamepadButton::FaceButtonUp: data.m_Storage = "FaceButtonUp"; return;
        case Input::GamepadButton::FaceButtonRight: data.m_Storage = "FaceButtonRight"; return;
        case Input::GamepadButton::FaceButtonBottom: data.m_Storage = "FaceButtonBottom"; return;
        case Input::GamepadButton::FaceButtonLeft: data.m_Storage = "FaceButtonLeft"; return;
        case Input::GamepadButton::R1: data.m_Storage = "R1"; return;
        case Input::GamepadButton::R2: data.m_Storage = "R2"; return;
        case Input::GamepadButton::R3: data.m_Storage = "R3"; return;
        case Input::GamepadButton::R4: data.m_Storage = "R4"; return;
        case Input::GamepadButton::L1: data.m_Storage = "L1"; return;
        case Input::GamepadButton::L2: data.m_Storage = "L2"; return;
        case Input::GamepadButton::L3: data.m_Storage = "L3"; return;
        case Input::GamepadButton::L4: data.m_Storage = "L4"; return;
        case Input::GamepadButton::Start: data.m_Storage = "Start"; return;
        case Input::GamepadButton::Options: data.m_Storage = "Options"; return;
        }

    }
};

}
