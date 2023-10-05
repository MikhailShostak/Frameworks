#pragma once

namespace
{

struct InputReflectionType
{
    InputReflectionType()
    {
        Reflection::Add<Input::InputBinding>("Input.InputBinding");
        
        Reflection::Add<Input::Action>("Input.Action");
        Reflection::Add<Input::Context>("Input.Context");
        
        Reflection::Add<Input::MouseAxisBinding>("Input.MouseAxisBinding");
        Reflection::Add<Input::MouseButtonBinding>("Input.MouseButtonBinding");
        Reflection::Add<Input::KeyboardButtonBinding>("Input.KeyboardButtonBinding");
        Reflection::Add<Input::GamepadAxisBinding>("Input.GamepadAxisBinding");
        Reflection::Add<Input::GamepadButtonBinding>("Input.GamepadButtonBinding");

        Reflection::Add<Input::Subsystem>("Input.Subsystem");
    }
} inline InputReflection;

}
