#pragma once

namespace Graphics
{
class Window;
}

namespace Input
{

PUBLIC_API_EXPORT Input::Context &GetDebugContext();
PUBLIC_API_EXPORT List<SharedReference<Input::Action>> &GetNativeActions();

PUBLIC_API_EXPORT void Bind(Input::Context &context, const Array<SharedReference<Input::InputBinding>> &bindings, const Input::CallbackType &callback);
PUBLIC_API_EXPORT void Bind(Input::Context &context, const SharedReference<Input::InputBinding> &binding, const Input::CallbackType &callback);
PUBLIC_API_EXPORT void Bind(Context &context, const SharedReference<Input::InputBinding> &binding, bool &ToggleValue);
PUBLIC_API_EXPORT void Bind(const StringID &actionID, const Input::CallbackType &callback);

PUBLIC_API_EXPORT void AddContext(Input::Context &context, size_t index = -1);
PUBLIC_API_EXPORT void AddContext(const StringID &contextID, size_t index = -1);
PUBLIC_API_EXPORT void RemoveContext(Input::Context &context);
PUBLIC_API_EXPORT void RemoveContext(const StringID &contextID);

class PUBLIC_API_EXPORT Subsystem : public Core::Subsystem
{
public:
    using Super = Core::Subsystem;

    Array<Context*> InputContexts;

    Subsystem();

    template<typename ButtonBindingType, typename ButtonType>
    void ProcessButtonInput(Graphics::Window &Window, ButtonType Button, bool Pressed)
    {
        for (auto &InputContext : InputContexts)
        {
            for (auto &ActionBinding : InputContext->ActionBindings)
            {
                for (auto &InputBinding : ActionBinding.InputBindings)
                {
                    auto Binding = DynamicCast<ButtonBindingType>(InputBinding);
                    if (!Binding || Binding->Button != Button)
                    {
                        continue;
                    }

                    if (Binding->Pressed == Pressed)
                    {
                        if (Binding->Handled)
                        {
                            return;
                        }
                        else
                        {
                            continue;
                        }
                    }

                    Binding->Pressed = Pressed;
                    const float Value = (Pressed ? 1.0f : -1.0f);

                    ActionBinding.Value += Math::Swizzle4(Float4{ Value * Binding->Scale, 0.0f, 0.0f, 0.0f }, Binding->Swizzle);

                    Input::Event Event;
                    Event.Window = &Window;
                    Event.Value = ActionBinding.Value;
                    Event.Pressed = Pressed;
                    if (ActionBinding.Action->Trigger(Event))
                    {
                        Binding->Handled = true;
                        return;
                    }
                }
            }
        }
    }

    template<typename AxisBindingType>
    void ProcessAxisInput(Graphics::Window &Window, const uint64_t &Axis, const float Value)
    {
        for (auto &InputContext : InputContexts)
        {
            for (auto &ActionBinding : InputContext->ActionBindings)
            {
                for (auto &InputBinding : ActionBinding.InputBindings)
                {
                    //AxisBindingType *Binding = std::get_if<AxisBindingType>(&InputBinding);
                    auto Binding = DynamicCast<AxisBindingType>(InputBinding);
                    if (!Binding || Binding->Axis != Axis)
                    {
                        continue;
                    }

                    ActionBinding.Value += Math::Swizzle4(Float4{ Value * Binding->Scale, 0.0f, 0.0f, 0.0f }, Binding->Swizzle);
                    
                    Input::Event Event;
                    Event.Window = &Window;
                    Event.Value = ActionBinding.Value;
                    Event.Pressed = false;
                    if (ActionBinding.Action->Trigger(Event))
                    {
                        Binding->Handled = true;
                        return;
                    }
                }
            }
        }
    }
};

}
