#pragma once

namespace UI
{
struct PUBLIC_API_EXPORT AbsoluteLayout
    : public UI::Layout
{
    using This = AbsoluteLayout;
    using Super = UI::Layout;

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual bool/*Success*/ OnLayout(ECS::Entity & Entity);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
