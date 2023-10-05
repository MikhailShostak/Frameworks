#include <imgui.h>

namespace MapUtils
{

template<typename KeyType, typename ValueType>
auto &FindOrAdd(Map<KeyType, ValueType> &Map, const KeyType &Key)
{
    auto It = Map.find(Key);
    if (It == Map.end())
    {
        It = Map.insert({ Key, ValueType() }).first;
    }
    return It->second;
}

template<typename KeyType, typename ValueType>
const auto &FindOrAdd(const Map<KeyType, ValueType> &Map, const KeyType &Key)
{
    auto It = Map.find(Key);
    if (It == Map.end())
    {
        It = Map.insert({ Key, ValueType() }).first;
    }
    return It->second;
}

}

Input::GamepadButton RemapInput(uint64_t Button)
{
    return Input::GamepadButton(Button);
}

Input::MouseButton RemapInput(sf::Mouse::Button Button)
{
    switch(Button)
    {
    case sf::Mouse::Button::Left: return Input::MouseButton::Left;
    case sf::Mouse::Button::Right: return Input::MouseButton::Right;
    case sf::Mouse::Button::Middle: return Input::MouseButton::Middle;
    case sf::Mouse::Button::XButton1: return Input::MouseButton::Extra1;
    case sf::Mouse::Button::XButton2: return Input::MouseButton::Extra2;
    default: return Input::MouseButton::Undefined;
    }
}

Input::KeyboardButton RemapInput(sf::Keyboard::Key Key)
{
    switch(Key)
    {
    case sf::Keyboard::Key::A: return Input::KeyboardButton::A;
    case sf::Keyboard::Key::B: return Input::KeyboardButton::B;
    case sf::Keyboard::Key::C: return Input::KeyboardButton::C;
    case sf::Keyboard::Key::D: return Input::KeyboardButton::D;
    case sf::Keyboard::Key::E: return Input::KeyboardButton::E;
    case sf::Keyboard::Key::F: return Input::KeyboardButton::F;
    case sf::Keyboard::Key::G: return Input::KeyboardButton::G;
    case sf::Keyboard::Key::H: return Input::KeyboardButton::H;
    case sf::Keyboard::Key::I: return Input::KeyboardButton::I;
    case sf::Keyboard::Key::J: return Input::KeyboardButton::J;
    case sf::Keyboard::Key::K: return Input::KeyboardButton::K;
    case sf::Keyboard::Key::L: return Input::KeyboardButton::L;
    case sf::Keyboard::Key::M: return Input::KeyboardButton::M;
    case sf::Keyboard::Key::N: return Input::KeyboardButton::N;
    case sf::Keyboard::Key::O: return Input::KeyboardButton::O;
    case sf::Keyboard::Key::P: return Input::KeyboardButton::P;
    case sf::Keyboard::Key::Q: return Input::KeyboardButton::Q;
    case sf::Keyboard::Key::R: return Input::KeyboardButton::R;
    case sf::Keyboard::Key::S: return Input::KeyboardButton::S;
    case sf::Keyboard::Key::T: return Input::KeyboardButton::T;
    case sf::Keyboard::Key::U: return Input::KeyboardButton::U;
    case sf::Keyboard::Key::V: return Input::KeyboardButton::V;
    case sf::Keyboard::Key::W: return Input::KeyboardButton::W;
    case sf::Keyboard::Key::X: return Input::KeyboardButton::X;
    case sf::Keyboard::Key::Y: return Input::KeyboardButton::Y;
    case sf::Keyboard::Key::Z: return Input::KeyboardButton::Z;
    case sf::Keyboard::Key::Num0: return Input::KeyboardButton::Key0;
    case sf::Keyboard::Key::Num1: return Input::KeyboardButton::Key1;
    case sf::Keyboard::Key::Num2: return Input::KeyboardButton::Key2;
    case sf::Keyboard::Key::Num3: return Input::KeyboardButton::Key3;
    case sf::Keyboard::Key::Num4: return Input::KeyboardButton::Key4;
    case sf::Keyboard::Key::Num5: return Input::KeyboardButton::Key5;
    case sf::Keyboard::Key::Num6: return Input::KeyboardButton::Key6;
    case sf::Keyboard::Key::Num7: return Input::KeyboardButton::Key7;
    case sf::Keyboard::Key::Num8: return Input::KeyboardButton::Key8;
    case sf::Keyboard::Key::Num9: return Input::KeyboardButton::Key9;
    case sf::Keyboard::Key::Escape: return Input::KeyboardButton::Escape;
    case sf::Keyboard::Key::LControl: return Input::KeyboardButton::LeftControl;
    case sf::Keyboard::Key::LShift: return Input::KeyboardButton::LeftShift;
    case sf::Keyboard::Key::LAlt: return Input::KeyboardButton::LeftAlt;
    case sf::Keyboard::Key::LSystem: return Input::KeyboardButton::LeftSystem;
    case sf::Keyboard::Key::RControl: return Input::KeyboardButton::RightControl;
    case sf::Keyboard::Key::RShift: return Input::KeyboardButton::RightShift;
    case sf::Keyboard::Key::RAlt: return Input::KeyboardButton::RightAlt;
    case sf::Keyboard::Key::RSystem: return Input::KeyboardButton::RightSystem;
    case sf::Keyboard::Key::Menu: return Input::KeyboardButton::Menu;
    case sf::Keyboard::Key::LBracket: return Input::KeyboardButton::LeftBracket;
    case sf::Keyboard::Key::RBracket: return Input::KeyboardButton::RightBracket;
    case sf::Keyboard::Key::Semicolon: return Input::KeyboardButton::Semicolon;
    case sf::Keyboard::Key::Comma: return Input::KeyboardButton::Comma;
    case sf::Keyboard::Key::Period: return Input::KeyboardButton::Period;
    case sf::Keyboard::Key::Apostrophe: return Input::KeyboardButton::Apostrophe;
    case sf::Keyboard::Key::Slash: return Input::KeyboardButton::Slash;
    case sf::Keyboard::Key::Backslash: return Input::KeyboardButton::Backslash;
    case sf::Keyboard::Key::Grave: return Input::KeyboardButton::Grave;
    case sf::Keyboard::Key::Equal: return Input::KeyboardButton::Equal;
    case sf::Keyboard::Key::Hyphen: return Input::KeyboardButton::Hyphen;
    case sf::Keyboard::Key::Space: return Input::KeyboardButton::Space;
    case sf::Keyboard::Key::Enter: return Input::KeyboardButton::Enter;
    case sf::Keyboard::Key::Backspace: return Input::KeyboardButton::Backspace;
    case sf::Keyboard::Key::Tab: return Input::KeyboardButton::Tab;
    case sf::Keyboard::Key::PageUp: return Input::KeyboardButton::PageUp;
    case sf::Keyboard::Key::PageDown: return Input::KeyboardButton::PageDown;
    case sf::Keyboard::Key::End: return Input::KeyboardButton::End;
    case sf::Keyboard::Key::Home: return Input::KeyboardButton::Home;
    case sf::Keyboard::Key::Insert: return Input::KeyboardButton::Insert;
    case sf::Keyboard::Key::Delete: return Input::KeyboardButton::Delete;
    case sf::Keyboard::Key::Add: return Input::KeyboardButton::Add;
    case sf::Keyboard::Key::Subtract: return Input::KeyboardButton::Subtract;
    case sf::Keyboard::Key::Multiply: return Input::KeyboardButton::Multiply;
    case sf::Keyboard::Key::Divide: return Input::KeyboardButton::Divide;
    case sf::Keyboard::Key::Left: return Input::KeyboardButton::Left;
    case sf::Keyboard::Key::Right: return Input::KeyboardButton::Right;
    case sf::Keyboard::Key::Up: return Input::KeyboardButton::Up;
    case sf::Keyboard::Key::Down: return Input::KeyboardButton::Down;
    case sf::Keyboard::Key::Numpad0: return Input::KeyboardButton::Numpad0;
    case sf::Keyboard::Key::Numpad1: return Input::KeyboardButton::Numpad1;
    case sf::Keyboard::Key::Numpad2: return Input::KeyboardButton::Numpad2;
    case sf::Keyboard::Key::Numpad3: return Input::KeyboardButton::Numpad3;
    case sf::Keyboard::Key::Numpad4: return Input::KeyboardButton::Numpad4;
    case sf::Keyboard::Key::Numpad5: return Input::KeyboardButton::Numpad5;
    case sf::Keyboard::Key::Numpad6: return Input::KeyboardButton::Numpad6;
    case sf::Keyboard::Key::Numpad7: return Input::KeyboardButton::Numpad7;
    case sf::Keyboard::Key::Numpad8: return Input::KeyboardButton::Numpad8;
    case sf::Keyboard::Key::Numpad9: return Input::KeyboardButton::Numpad9;
    case sf::Keyboard::Key::F1: return Input::KeyboardButton::F1;
    case sf::Keyboard::Key::F2: return Input::KeyboardButton::F2;
    case sf::Keyboard::Key::F3: return Input::KeyboardButton::F3;
    case sf::Keyboard::Key::F4: return Input::KeyboardButton::F4;
    case sf::Keyboard::Key::F5: return Input::KeyboardButton::F5;
    case sf::Keyboard::Key::F6: return Input::KeyboardButton::F6;
    case sf::Keyboard::Key::F7: return Input::KeyboardButton::F7;
    case sf::Keyboard::Key::F8: return Input::KeyboardButton::F8;
    case sf::Keyboard::Key::F9: return Input::KeyboardButton::F9;
    case sf::Keyboard::Key::F10: return Input::KeyboardButton::F10;
    case sf::Keyboard::Key::F11: return Input::KeyboardButton::F11;
    case sf::Keyboard::Key::F12: return Input::KeyboardButton::F12;
    case sf::Keyboard::Key::F13: return Input::KeyboardButton::F13;
    case sf::Keyboard::Key::F14: return Input::KeyboardButton::F14;
    case sf::Keyboard::Key::F15: return Input::KeyboardButton::F15;
    case sf::Keyboard::Key::Pause: return Input::KeyboardButton::Pause;
    default: return Input::KeyboardButton::Undefined;
    }
}

namespace Graphics
{

sf::Clock Clock;
sf::Time DeltaTime;

void UpdateScreenSurface(Graphics::SFMLWindow &Window)
{
    sf::View View = Window.Handle.getView();
    View.setSize({ float(Window.Size[0]) / Window.UnitSize[0], float(-Window.Size[1]) / Window.UnitSize[1]});
    View.setCenter({ 0, 0 });
    Window.Handle.setView(View);
}

SFMLSubsystem::SFMLSubsystem()
{
    Initialize();
}

void SFMLSubsystem::Load()
{
    Input = Core::FindSubsystem<Input::Subsystem>();
}

bool HandleInputEvent(Input::Subsystem &Subsystem, Graphics::Window &Window, const sf::Event &Event)
{
    if (Event.type == sf::Event::MouseMoved)
    {
        Int2 CurrentMousePosition{ Event.mouseMove.x, Event.mouseMove.y };
        auto MouseDelta = CurrentMousePosition - Window.MousePosition;
        Window.MousePosition = CurrentMousePosition;
        Subsystem.ProcessAxisInput<Input::MouseAxisBinding>(Window, 0, float(MouseDelta.x));
        Subsystem.ProcessAxisInput<Input::MouseAxisBinding>(Window, 1, float(MouseDelta.y));
    }
    else if (Event.type == sf::Event::MouseWheelMoved)
    {
        Subsystem.ProcessAxisInput<Input::MouseAxisBinding>(Window, 2, float(Event.mouseWheel.x));
        Subsystem.ProcessAxisInput<Input::MouseAxisBinding>(Window, 3, float(Event.mouseWheel.y));
    }
    else if (Event.type == sf::Event::JoystickMoved)
    {
        Subsystem.ProcessAxisInput<Input::GamepadAxisBinding>(Window, Event.joystickMove.axis, Event.joystickMove.position / 100.0f);
    }
    else if (Event.type == sf::Event::KeyPressed)
    {
        Subsystem.ProcessButtonInput<Input::KeyboardButtonBinding>(Window, RemapInput(Event.key.code), true);
    }
    else if (Event.type == sf::Event::KeyReleased)
    {
        Subsystem.ProcessButtonInput<Input::KeyboardButtonBinding>(Window, RemapInput(Event.key.code), false);
    }
    else if (Event.type == sf::Event::MouseButtonPressed)
    {
        Subsystem.ProcessButtonInput<Input::MouseButtonBinding>(Window, RemapInput(Event.mouseButton.button), true);
    }
    else if (Event.type == sf::Event::MouseButtonReleased)
    {
        Subsystem.ProcessButtonInput<Input::MouseButtonBinding>(Window, RemapInput(Event.mouseButton.button), false);
    }
    else if (Event.type == sf::Event::JoystickButtonPressed)
    {
        Subsystem.ProcessButtonInput<Input::GamepadButtonBinding>(Window, RemapInput(Event.joystickButton.button), true);
    }
    else if (Event.type == sf::Event::JoystickButtonReleased)
    {
        Subsystem.ProcessButtonInput<Input::GamepadButtonBinding>(Window, RemapInput(Event.joystickButton.button), false);
    }

    return false;
}

void SFMLSubsystem::Update()
{
    static bool RenderImGui = false;

    DeltaTime = Clock.restart();

    for (auto &Window : Windows)
    {
        auto SFMLWindow = StaticCast<Graphics::SFMLWindow>(Window);

        if (!SFMLWindow->Initialized)
        {
            SFMLWindow->Initialized = true;
            SFMLWindow->UnitSize = 100.0f;
            SFMLWindow->Handle.create(sf::VideoMode(Window->Size[0], Window->Size[1]), Window->Title.data());
            UpdateScreenSurface(*SFMLWindow);
            ImGui::SFML::Init(SFMLWindow->Handle);

            ImGuiIO &io = ImGui::GetIO();
            io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        }

        Array<sf::Event> Events;
        if (SFMLWindow->Handle.isOpen())
        {
            sf::Event Event;
            while (SFMLWindow->Handle.pollEvent(Event))
            {
                if (Event.type == sf::Event::Closed)
                {
                    SFMLWindow->Handle.close();
                }

                if (Event.type == sf::Event::Resized)
                {
                    SFMLWindow->Size[0] = Event.size.width;
                    SFMLWindow->Size[1] = Event.size.height;
                    UpdateScreenSurface(*SFMLWindow);
                }

                Events.push_back(Event);
                ImGui::SFML::ProcessEvent(SFMLWindow->Handle, Event);
            }

            SFMLWindow->DeltaTime = SFMLWindow->FrameCounter.CountAs<DateTime::SecondRatio>();
            ImGui::SFML::Update(SFMLWindow->Handle, sf::seconds(SFMLWindow->DeltaTime.count()));
            if (Window->Scene)
            {
                Window->Scene->Execute(*SFMLWindow);
            }
            ImGui::SFML::Render(SFMLWindow->Handle);

            SFMLWindow->Handle.display();
            SFMLWindow->Handle.clear();

            for (auto &Event : Events)
            {
                if (HandleInputEvent(*Input, *Window, Event))
                {
                    break;
                }
            }
        }
    }
}

void SFMLSubsystem::Unload()
{

}

}
