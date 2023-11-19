#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT EntityInstance
{
    using This = EntityInstance;
    StringID Name {};
    SharedReference<ECS::EntityDefinition> Definition {};
    Serialization::Data Values {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Name"] & Name;
        data["Definition"] & Definition;
        data["Values"] & Values;
    }

    void Initialize()
    {
    }
};
}
