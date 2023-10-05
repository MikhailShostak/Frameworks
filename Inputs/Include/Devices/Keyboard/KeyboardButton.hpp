#pragma once

namespace Input
{
enum class KeyboardButton
{
    Undefined,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    Key1,
    Key2,
    Key3,
    Key4,
    Key5,
    Key6,
    Key7,
    Key8,
    Key9,
    Key0,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    LeftAlt,
    LeftControl,
    LeftShift,
    LeftSystem,
    RightAlt,
    RightControl,
    RightShift,
    RightSystem,
    Up,
    Left,
    Down,
    Right,
    Space,
    Tab,
    Backspace,
    Enter,
    Escape,
    CapsLock,
    Apostrophe,
    Grave,
    Minus,
    Equal,
    Hyphen,
    Slash,
    Backslash,
    LeftBracket,
    RightBracket,
    Semicolon,
    Quote,
    Comma,
    Period,
    Insert,
    Home,
    Delete,
    End,
    PageUp,
    PageDown,
    NumLock,
    Numpad0,
    Numpad1,
    Numpad2,
    Numpad3,
    Numpad4,
    Numpad5,
    Numpad6,
    Numpad7,
    Numpad8,
    Numpad9,
    Add,
    Subtract,
    Multiply,
    Divide,
    NumpadDecimal,
    NumpadEnter,
    PrintScreen,
    ScrollLock,
    Pause,
    Menu,
};
}

namespace Serialization
{
template<>
struct Serializer<InputValue, Input::KeyboardButton>
{
    template<typename InputValue, typename ValueType>
    static void Write(InputValue&& data, ValueType&& value)
    {
        if (data.m_Storage.IsScalar())
        {
            const auto &valueName = data.m_Storage.template as<std::string>();
            if (valueName == "Undefined") { value = Input::KeyboardButton::Undefined; return; }
            if (valueName == "A") { value = Input::KeyboardButton::A; return; }
            if (valueName == "B") { value = Input::KeyboardButton::B; return; }
            if (valueName == "C") { value = Input::KeyboardButton::C; return; }
            if (valueName == "D") { value = Input::KeyboardButton::D; return; }
            if (valueName == "E") { value = Input::KeyboardButton::E; return; }
            if (valueName == "F") { value = Input::KeyboardButton::F; return; }
            if (valueName == "G") { value = Input::KeyboardButton::G; return; }
            if (valueName == "H") { value = Input::KeyboardButton::H; return; }
            if (valueName == "I") { value = Input::KeyboardButton::I; return; }
            if (valueName == "J") { value = Input::KeyboardButton::J; return; }
            if (valueName == "K") { value = Input::KeyboardButton::K; return; }
            if (valueName == "L") { value = Input::KeyboardButton::L; return; }
            if (valueName == "M") { value = Input::KeyboardButton::M; return; }
            if (valueName == "N") { value = Input::KeyboardButton::N; return; }
            if (valueName == "O") { value = Input::KeyboardButton::O; return; }
            if (valueName == "P") { value = Input::KeyboardButton::P; return; }
            if (valueName == "Q") { value = Input::KeyboardButton::Q; return; }
            if (valueName == "R") { value = Input::KeyboardButton::R; return; }
            if (valueName == "S") { value = Input::KeyboardButton::S; return; }
            if (valueName == "T") { value = Input::KeyboardButton::T; return; }
            if (valueName == "U") { value = Input::KeyboardButton::U; return; }
            if (valueName == "V") { value = Input::KeyboardButton::V; return; }
            if (valueName == "W") { value = Input::KeyboardButton::W; return; }
            if (valueName == "X") { value = Input::KeyboardButton::X; return; }
            if (valueName == "Y") { value = Input::KeyboardButton::Y; return; }
            if (valueName == "Z") { value = Input::KeyboardButton::Z; return; }
            if (valueName == "Key1") { value = Input::KeyboardButton::Key1; return; }
            if (valueName == "Key2") { value = Input::KeyboardButton::Key2; return; }
            if (valueName == "Key3") { value = Input::KeyboardButton::Key3; return; }
            if (valueName == "Key4") { value = Input::KeyboardButton::Key4; return; }
            if (valueName == "Key5") { value = Input::KeyboardButton::Key5; return; }
            if (valueName == "Key6") { value = Input::KeyboardButton::Key6; return; }
            if (valueName == "Key7") { value = Input::KeyboardButton::Key7; return; }
            if (valueName == "Key8") { value = Input::KeyboardButton::Key8; return; }
            if (valueName == "Key9") { value = Input::KeyboardButton::Key9; return; }
            if (valueName == "Key0") { value = Input::KeyboardButton::Key0; return; }
            if (valueName == "F1") { value = Input::KeyboardButton::F1; return; }
            if (valueName == "F2") { value = Input::KeyboardButton::F2; return; }
            if (valueName == "F3") { value = Input::KeyboardButton::F3; return; }
            if (valueName == "F4") { value = Input::KeyboardButton::F4; return; }
            if (valueName == "F5") { value = Input::KeyboardButton::F5; return; }
            if (valueName == "F6") { value = Input::KeyboardButton::F6; return; }
            if (valueName == "F7") { value = Input::KeyboardButton::F7; return; }
            if (valueName == "F8") { value = Input::KeyboardButton::F8; return; }
            if (valueName == "F9") { value = Input::KeyboardButton::F9; return; }
            if (valueName == "F10") { value = Input::KeyboardButton::F10; return; }
            if (valueName == "F11") { value = Input::KeyboardButton::F11; return; }
            if (valueName == "F12") { value = Input::KeyboardButton::F12; return; }
            if (valueName == "F13") { value = Input::KeyboardButton::F13; return; }
            if (valueName == "F14") { value = Input::KeyboardButton::F14; return; }
            if (valueName == "F15") { value = Input::KeyboardButton::F15; return; }
            if (valueName == "LeftAlt") { value = Input::KeyboardButton::LeftAlt; return; }
            if (valueName == "LeftControl") { value = Input::KeyboardButton::LeftControl; return; }
            if (valueName == "LeftShift") { value = Input::KeyboardButton::LeftShift; return; }
            if (valueName == "LeftSystem") { value = Input::KeyboardButton::LeftSystem; return; }
            if (valueName == "RightAlt") { value = Input::KeyboardButton::RightAlt; return; }
            if (valueName == "RightControl") { value = Input::KeyboardButton::RightControl; return; }
            if (valueName == "RightShift") { value = Input::KeyboardButton::RightShift; return; }
            if (valueName == "RightSystem") { value = Input::KeyboardButton::RightSystem; return; }
            if (valueName == "Up") { value = Input::KeyboardButton::Up; return; }
            if (valueName == "Left") { value = Input::KeyboardButton::Left; return; }
            if (valueName == "Down") { value = Input::KeyboardButton::Down; return; }
            if (valueName == "Right") { value = Input::KeyboardButton::Right; return; }
            if (valueName == "Space") { value = Input::KeyboardButton::Space; return; }
            if (valueName == "Tab") { value = Input::KeyboardButton::Tab; return; }
            if (valueName == "Backspace") { value = Input::KeyboardButton::Backspace; return; }
            if (valueName == "Enter") { value = Input::KeyboardButton::Enter; return; }
            if (valueName == "Escape") { value = Input::KeyboardButton::Escape; return; }
            if (valueName == "CapsLock") { value = Input::KeyboardButton::CapsLock; return; }
            if (valueName == "Apostrophe") { value = Input::KeyboardButton::Apostrophe; return; }
            if (valueName == "Grave") { value = Input::KeyboardButton::Grave; return; }
            if (valueName == "Minus") { value = Input::KeyboardButton::Minus; return; }
            if (valueName == "Equal") { value = Input::KeyboardButton::Equal; return; }
            if (valueName == "Hyphen") { value = Input::KeyboardButton::Hyphen; return; }
            if (valueName == "Slash") { value = Input::KeyboardButton::Slash; return; }
            if (valueName == "Backslash") { value = Input::KeyboardButton::Backslash; return; }
            if (valueName == "LeftBracket") { value = Input::KeyboardButton::LeftBracket; return; }
            if (valueName == "RightBracket") { value = Input::KeyboardButton::RightBracket; return; }
            if (valueName == "Semicolon") { value = Input::KeyboardButton::Semicolon; return; }
            if (valueName == "Quote") { value = Input::KeyboardButton::Quote; return; }
            if (valueName == "Comma") { value = Input::KeyboardButton::Comma; return; }
            if (valueName == "Period") { value = Input::KeyboardButton::Period; return; }
            if (valueName == "Insert") { value = Input::KeyboardButton::Insert; return; }
            if (valueName == "Home") { value = Input::KeyboardButton::Home; return; }
            if (valueName == "Delete") { value = Input::KeyboardButton::Delete; return; }
            if (valueName == "End") { value = Input::KeyboardButton::End; return; }
            if (valueName == "PageUp") { value = Input::KeyboardButton::PageUp; return; }
            if (valueName == "PageDown") { value = Input::KeyboardButton::PageDown; return; }
            if (valueName == "NumLock") { value = Input::KeyboardButton::NumLock; return; }
            if (valueName == "Numpad0") { value = Input::KeyboardButton::Numpad0; return; }
            if (valueName == "Numpad1") { value = Input::KeyboardButton::Numpad1; return; }
            if (valueName == "Numpad2") { value = Input::KeyboardButton::Numpad2; return; }
            if (valueName == "Numpad3") { value = Input::KeyboardButton::Numpad3; return; }
            if (valueName == "Numpad4") { value = Input::KeyboardButton::Numpad4; return; }
            if (valueName == "Numpad5") { value = Input::KeyboardButton::Numpad5; return; }
            if (valueName == "Numpad6") { value = Input::KeyboardButton::Numpad6; return; }
            if (valueName == "Numpad7") { value = Input::KeyboardButton::Numpad7; return; }
            if (valueName == "Numpad8") { value = Input::KeyboardButton::Numpad8; return; }
            if (valueName == "Numpad9") { value = Input::KeyboardButton::Numpad9; return; }
            if (valueName == "Add") { value = Input::KeyboardButton::Add; return; }
            if (valueName == "Subtract") { value = Input::KeyboardButton::Subtract; return; }
            if (valueName == "Multiply") { value = Input::KeyboardButton::Multiply; return; }
            if (valueName == "Divide") { value = Input::KeyboardButton::Divide; return; }
            if (valueName == "NumpadDecimal") { value = Input::KeyboardButton::NumpadDecimal; return; }
            if (valueName == "NumpadEnter") { value = Input::KeyboardButton::NumpadEnter; return; }
            if (valueName == "PrintScreen") { value = Input::KeyboardButton::PrintScreen; return; }
            if (valueName == "ScrollLock") { value = Input::KeyboardButton::ScrollLock; return; }
            if (valueName == "Pause") { value = Input::KeyboardButton::Pause; return; }
            if (valueName == "Menu") { value = Input::KeyboardButton::Menu; return; }
            value = Input::KeyboardButton::Undefined;

        }
    }
};

template<>
struct Serializer<OutputValue, Input::KeyboardButton>
{
    template<typename OutputValue, typename ValueType>
    static void Write(OutputValue&& data, ValueType&& value)
    {

        switch(value)
        {
        case Input::KeyboardButton::Undefined: data.m_Storage = "Undefined"; return;
        case Input::KeyboardButton::A: data.m_Storage = "A"; return;
        case Input::KeyboardButton::B: data.m_Storage = "B"; return;
        case Input::KeyboardButton::C: data.m_Storage = "C"; return;
        case Input::KeyboardButton::D: data.m_Storage = "D"; return;
        case Input::KeyboardButton::E: data.m_Storage = "E"; return;
        case Input::KeyboardButton::F: data.m_Storage = "F"; return;
        case Input::KeyboardButton::G: data.m_Storage = "G"; return;
        case Input::KeyboardButton::H: data.m_Storage = "H"; return;
        case Input::KeyboardButton::I: data.m_Storage = "I"; return;
        case Input::KeyboardButton::J: data.m_Storage = "J"; return;
        case Input::KeyboardButton::K: data.m_Storage = "K"; return;
        case Input::KeyboardButton::L: data.m_Storage = "L"; return;
        case Input::KeyboardButton::M: data.m_Storage = "M"; return;
        case Input::KeyboardButton::N: data.m_Storage = "N"; return;
        case Input::KeyboardButton::O: data.m_Storage = "O"; return;
        case Input::KeyboardButton::P: data.m_Storage = "P"; return;
        case Input::KeyboardButton::Q: data.m_Storage = "Q"; return;
        case Input::KeyboardButton::R: data.m_Storage = "R"; return;
        case Input::KeyboardButton::S: data.m_Storage = "S"; return;
        case Input::KeyboardButton::T: data.m_Storage = "T"; return;
        case Input::KeyboardButton::U: data.m_Storage = "U"; return;
        case Input::KeyboardButton::V: data.m_Storage = "V"; return;
        case Input::KeyboardButton::W: data.m_Storage = "W"; return;
        case Input::KeyboardButton::X: data.m_Storage = "X"; return;
        case Input::KeyboardButton::Y: data.m_Storage = "Y"; return;
        case Input::KeyboardButton::Z: data.m_Storage = "Z"; return;
        case Input::KeyboardButton::Key1: data.m_Storage = "Key1"; return;
        case Input::KeyboardButton::Key2: data.m_Storage = "Key2"; return;
        case Input::KeyboardButton::Key3: data.m_Storage = "Key3"; return;
        case Input::KeyboardButton::Key4: data.m_Storage = "Key4"; return;
        case Input::KeyboardButton::Key5: data.m_Storage = "Key5"; return;
        case Input::KeyboardButton::Key6: data.m_Storage = "Key6"; return;
        case Input::KeyboardButton::Key7: data.m_Storage = "Key7"; return;
        case Input::KeyboardButton::Key8: data.m_Storage = "Key8"; return;
        case Input::KeyboardButton::Key9: data.m_Storage = "Key9"; return;
        case Input::KeyboardButton::Key0: data.m_Storage = "Key0"; return;
        case Input::KeyboardButton::F1: data.m_Storage = "F1"; return;
        case Input::KeyboardButton::F2: data.m_Storage = "F2"; return;
        case Input::KeyboardButton::F3: data.m_Storage = "F3"; return;
        case Input::KeyboardButton::F4: data.m_Storage = "F4"; return;
        case Input::KeyboardButton::F5: data.m_Storage = "F5"; return;
        case Input::KeyboardButton::F6: data.m_Storage = "F6"; return;
        case Input::KeyboardButton::F7: data.m_Storage = "F7"; return;
        case Input::KeyboardButton::F8: data.m_Storage = "F8"; return;
        case Input::KeyboardButton::F9: data.m_Storage = "F9"; return;
        case Input::KeyboardButton::F10: data.m_Storage = "F10"; return;
        case Input::KeyboardButton::F11: data.m_Storage = "F11"; return;
        case Input::KeyboardButton::F12: data.m_Storage = "F12"; return;
        case Input::KeyboardButton::F13: data.m_Storage = "F13"; return;
        case Input::KeyboardButton::F14: data.m_Storage = "F14"; return;
        case Input::KeyboardButton::F15: data.m_Storage = "F15"; return;
        case Input::KeyboardButton::LeftAlt: data.m_Storage = "LeftAlt"; return;
        case Input::KeyboardButton::LeftControl: data.m_Storage = "LeftControl"; return;
        case Input::KeyboardButton::LeftShift: data.m_Storage = "LeftShift"; return;
        case Input::KeyboardButton::LeftSystem: data.m_Storage = "LeftSystem"; return;
        case Input::KeyboardButton::RightAlt: data.m_Storage = "RightAlt"; return;
        case Input::KeyboardButton::RightControl: data.m_Storage = "RightControl"; return;
        case Input::KeyboardButton::RightShift: data.m_Storage = "RightShift"; return;
        case Input::KeyboardButton::RightSystem: data.m_Storage = "RightSystem"; return;
        case Input::KeyboardButton::Up: data.m_Storage = "Up"; return;
        case Input::KeyboardButton::Left: data.m_Storage = "Left"; return;
        case Input::KeyboardButton::Down: data.m_Storage = "Down"; return;
        case Input::KeyboardButton::Right: data.m_Storage = "Right"; return;
        case Input::KeyboardButton::Space: data.m_Storage = "Space"; return;
        case Input::KeyboardButton::Tab: data.m_Storage = "Tab"; return;
        case Input::KeyboardButton::Backspace: data.m_Storage = "Backspace"; return;
        case Input::KeyboardButton::Enter: data.m_Storage = "Enter"; return;
        case Input::KeyboardButton::Escape: data.m_Storage = "Escape"; return;
        case Input::KeyboardButton::CapsLock: data.m_Storage = "CapsLock"; return;
        case Input::KeyboardButton::Apostrophe: data.m_Storage = "Apostrophe"; return;
        case Input::KeyboardButton::Grave: data.m_Storage = "Grave"; return;
        case Input::KeyboardButton::Minus: data.m_Storage = "Minus"; return;
        case Input::KeyboardButton::Equal: data.m_Storage = "Equal"; return;
        case Input::KeyboardButton::Hyphen: data.m_Storage = "Hyphen"; return;
        case Input::KeyboardButton::Slash: data.m_Storage = "Slash"; return;
        case Input::KeyboardButton::Backslash: data.m_Storage = "Backslash"; return;
        case Input::KeyboardButton::LeftBracket: data.m_Storage = "LeftBracket"; return;
        case Input::KeyboardButton::RightBracket: data.m_Storage = "RightBracket"; return;
        case Input::KeyboardButton::Semicolon: data.m_Storage = "Semicolon"; return;
        case Input::KeyboardButton::Quote: data.m_Storage = "Quote"; return;
        case Input::KeyboardButton::Comma: data.m_Storage = "Comma"; return;
        case Input::KeyboardButton::Period: data.m_Storage = "Period"; return;
        case Input::KeyboardButton::Insert: data.m_Storage = "Insert"; return;
        case Input::KeyboardButton::Home: data.m_Storage = "Home"; return;
        case Input::KeyboardButton::Delete: data.m_Storage = "Delete"; return;
        case Input::KeyboardButton::End: data.m_Storage = "End"; return;
        case Input::KeyboardButton::PageUp: data.m_Storage = "PageUp"; return;
        case Input::KeyboardButton::PageDown: data.m_Storage = "PageDown"; return;
        case Input::KeyboardButton::NumLock: data.m_Storage = "NumLock"; return;
        case Input::KeyboardButton::Numpad0: data.m_Storage = "Numpad0"; return;
        case Input::KeyboardButton::Numpad1: data.m_Storage = "Numpad1"; return;
        case Input::KeyboardButton::Numpad2: data.m_Storage = "Numpad2"; return;
        case Input::KeyboardButton::Numpad3: data.m_Storage = "Numpad3"; return;
        case Input::KeyboardButton::Numpad4: data.m_Storage = "Numpad4"; return;
        case Input::KeyboardButton::Numpad5: data.m_Storage = "Numpad5"; return;
        case Input::KeyboardButton::Numpad6: data.m_Storage = "Numpad6"; return;
        case Input::KeyboardButton::Numpad7: data.m_Storage = "Numpad7"; return;
        case Input::KeyboardButton::Numpad8: data.m_Storage = "Numpad8"; return;
        case Input::KeyboardButton::Numpad9: data.m_Storage = "Numpad9"; return;
        case Input::KeyboardButton::Add: data.m_Storage = "Add"; return;
        case Input::KeyboardButton::Subtract: data.m_Storage = "Subtract"; return;
        case Input::KeyboardButton::Multiply: data.m_Storage = "Multiply"; return;
        case Input::KeyboardButton::Divide: data.m_Storage = "Divide"; return;
        case Input::KeyboardButton::NumpadDecimal: data.m_Storage = "NumpadDecimal"; return;
        case Input::KeyboardButton::NumpadEnter: data.m_Storage = "NumpadEnter"; return;
        case Input::KeyboardButton::PrintScreen: data.m_Storage = "PrintScreen"; return;
        case Input::KeyboardButton::ScrollLock: data.m_Storage = "ScrollLock"; return;
        case Input::KeyboardButton::Pause: data.m_Storage = "Pause"; return;
        case Input::KeyboardButton::Menu: data.m_Storage = "Menu"; return;
        }

    }
};

}
