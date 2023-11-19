#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT EntityDefinition
{
    using This = EntityDefinition;
    Serialization::Data InstanceData {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["InstanceData"] & InstanceData;
    }

    void Initialize()
    {
    }
};
}
