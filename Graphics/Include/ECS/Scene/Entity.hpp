#pragma once

namespace ECS
{


struct PUBLIC_API_EXPORT Entity
{
    using EntityID = entt::entity;

    Graphics::Scene* Scene {};
    EntityID ID {};

    Entity() = default;
    Entity(const Entity& entity) = default;
    Entity& operator =(const Entity& entity) = default;
    Entity(Entity && entity) = default;
    Entity& operator =(Entity && entity) = default;

    Entity(Graphics::Scene* Scene, EntityID ID):
        Scene(Scene),
        ID(ID)
    {

    }

    template<typename Type>
    Type& AddComponent() { return Scene->Registry.emplace<Type>(ID); }

    template<typename ...Types>
    std::tuple<Types&...> AddComponents() { return { Scene->Registry.emplace<Types>(ID)... }; }

    template<typename Type>
    Type& GetComponent() { return Scene->Registry.get<Type>(ID); }

    template<typename ...Types>
    std::tuple<Types&...> GetComponents() { return Scene->Registry.get<Types...>(ID); }

    template<typename Type>
    Type* FindComponent() { return Scene->Registry.try_get<Type>(ID); }

    template<typename ...Types>
    std::tuple<Types*...> FindComponents() { return Scene->Registry.try_get<Types...>(ID); }

    explicit operator bool() const
    {
        return Scene && Scene->Registry.valid(ID);
    }
};

}
