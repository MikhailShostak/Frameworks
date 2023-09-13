#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT PersistentComponent
    : public ECS::EntityComponent
{
    using This = PersistentComponent;
    using Super = ECS::EntityComponent;
    String Name = {};
    Array<ECS::EntityComponent*> Components = {};

    virtual ~PersistentComponent() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Name"] & Name;
    }

    void Initialize()
    {
        Super::Initialize();
    }
};
}
