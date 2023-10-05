#pragma once

namespace Graphics
{
class Window;
class Scene;
}

#include "Bindings/InputBinding.hpp"
#include "Bindings/AxisBinding.hpp"
#include "Bindings/ButtonBinding.hpp"

#include "Devices/DeviceType.hpp"

#include "Devices/Mouse/MouseButton.hpp"
#include "Devices/Mouse/MouseAxisBinding.hpp"
#include "Devices/Mouse/MouseButtonBinding.hpp"

#include "Devices/Keyboard/KeyboardButton.hpp"
#include "Devices/Keyboard/KeyboardButtonBinding.hpp"

#include "Devices/Gamepad/GamepadButton.hpp"
#include "Devices/Gamepad/GamepadAxisBinding.hpp"
#include "Devices/Gamepad/GamepadButtonBinding.hpp"

#include "Input/Event.hpp"
#include "Input/Event.inl"
#include "Input/Global.inl"
#include "Input/Action.hpp"
#include "Input/Action.inl"
#include "Input/ActionBinding.hpp"
#include "Input/Context.hpp"
#include "Input/InputSubsystem.hpp"
