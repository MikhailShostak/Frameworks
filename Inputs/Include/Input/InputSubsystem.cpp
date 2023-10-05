#include ".Input.hpp"

namespace Input
{

Input::Context &GetDebugContext()
{
    static Input::Context DebugInputContext;
    return DebugInputContext;
}

List<SharedReference<Input::Action>> &GetNativeActions()
{
    static List<SharedReference<Input::Action>> NativeActions;
    return NativeActions;
}

void Bind(Input::Context &context, const Array<SharedReference<Input::InputBinding>> &bindings, const Input::CallbackType &callback)
{
    SharedReference<Input::Action> Action {new Input::Action{}};
    Action->Handlers.push_back(callback);
    GetNativeActions().push_back(Action);
    
    ArrayUtils::Add(context.ActionBindings, {
        GetNativeActions().back(), bindings
    });
}

void Bind(Input::Context &context, const SharedReference<Input::InputBinding> &binding, const Input::CallbackType &callback)
{
    Bind(context, Array<SharedReference<Input::InputBinding>>({ binding }), callback);
}

void Bind(Context &context, const SharedReference<Input::InputBinding> &binding, bool &ToggleValue)
{
    auto callback = [&ToggleValue](const Event &event)
    {
        if (!event.Pressed)
        {
            return false;
        }
        
        ToggleValue = !ToggleValue;
        return true;
    };

    Bind(context, binding, callback);
}

void Bind(const StringID &actionID, const Input::CallbackType &callback)
{
    RuntimeAssetStorage::Find<Input::Action>(actionID)->Handlers.push_back(callback);
}

void AddContext(Input::Context &context, size_t index)
{
    auto Subsystem = Core::FindSubsystem<Input::Subsystem>();
    ArrayUtils::Insert(Subsystem->InputContexts, index, &context);
}

void AddContext(const StringID &contextID, size_t index)
{
    auto Context = RuntimeAssetStorage::Find<Input::Context>(contextID);
    AddContext(*Context, index);
}

void RemoveContext(Input::Context &context)
{
    auto Subsystem = Core::FindSubsystem<Input::Subsystem>();
    ArrayUtils::Remove(Subsystem->InputContexts, &context);
}

void RemoveContext(const StringID &contextID)
{
    auto Context = RuntimeAssetStorage::Find<Input::Context>(contextID);
    RemoveContext(*Context);
}

Subsystem::Subsystem()
{
    InputContexts.push_back(&GetDebugContext());
}

}
