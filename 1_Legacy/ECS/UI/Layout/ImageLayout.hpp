#pragma once

namespace UI
{
struct PUBLIC_API_EXPORT ImageLayout
    : public UI::Layout
{
    using This = ImageLayout;
    using Super = UI::Layout;

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual bool/*Success*/ OnPrePass(ECS::Entity & Entity);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
