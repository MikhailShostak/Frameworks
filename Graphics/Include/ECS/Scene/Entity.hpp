#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT Entity
{
    using This = Entity;
    Graphics::Scene* Scene {};
    ECS::EntityID ID {};

    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }

    template<typename Type>
    Type& AddComponent() const { return Scene->Registry.emplace<Type>(ID); }

    template<typename ...Types>
    std::tuple<Types&...> AddComponents() const { return { Scene->Registry.emplace<Types>(ID)... }; }

    template<typename Type>
    Type& GetComponent() const { return Scene->Registry.get<Type>(ID); }

    template<typename ...Types>
    std::tuple<Types&...> GetComponents() const { return Scene->Registry.get<Types...>(ID); }

    template<typename Type>
    Type* FindComponent() const { return Scene->Registry.try_get<Type>(ID); }

    template<typename ...Types>
    std::tuple<Types*...> FindComponents() const { return Scene->Registry.try_get<Types...>(ID); }

    void Destroy() const { Scene->Registry.destroy(ID); }

    explicit operator bool() const
    {
        return Scene && Scene->Registry.valid(ID);
    }
};
}
