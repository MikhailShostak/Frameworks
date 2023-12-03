#pragma once

namespace UI
{
struct PUBLIC_API_EXPORT Layout
{
    using This = Layout;

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual bool/*Success*/ OnPrePass(ECS::Entity & Entity);
    virtual bool/*Success*/ OnLayout(ECS::Entity & Entity);

    void Initialize()
    {
    }
};
}
