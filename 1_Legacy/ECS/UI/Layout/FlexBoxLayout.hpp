#pragma once

namespace UI
{
struct PUBLIC_API_EXPORT FlexBoxLayout
    : public UI::Layout
{
    using This = FlexBoxLayout;
    using Super = UI::Layout;

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual bool/*Success*/ OnPrePass(ECS::Entity & Entity);
    virtual bool/*Success*/ OnLayout(ECS::Entity & Entity);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
