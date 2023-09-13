#pragma once

namespace ECS
{
template<typename ...ComponentTypes>
struct PUBLIC_API_EXPORT EntityTemplate
    : public ECS::Entity
{
    using This = EntityTemplate;
    using Super = ECS::Entity;
    
    std::tuple<ComponentTypes &...> Components;

    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
