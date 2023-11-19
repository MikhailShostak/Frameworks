#pragma once

namespace Serialization
{

template<>
struct PUBLIC_API_EXPORT ObjectSerializer<Graphics::Scene>
{
    template<typename DataType, typename ValueType>
    static void Serialize(DataType&& data, ValueType&& value)
    {
        //TODO: Restrict multithreaded allocation.
        Array<ECS::EntityInstance> Instances;
        data["Entities"] & Instances;
        
        for (auto& Instance : Instances)
        {
            ECS::Entity Entity = ECS::CreateEntity(value, Instance.Definition.get());
            Serialization::Deserialize(Instance.Values, Entity);
        }
    }
};

}
