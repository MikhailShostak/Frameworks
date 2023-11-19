#pragma once

//namespace Serialization
//{
//
//template<>
//struct PUBLIC_API_EXPORT ObjectSerializer<ECS::EntityDefinition>
//{
//    template<typename DataType, typename ValueType>
//    static void Serialize(DataType&& data, ValueType&& value)
//    {
//        //TODO: Restrict multithreaded allocation.
//        //Memory::GetParentEntity() = value;
//        //Array<UniqueReference<ECS::EntityComponent>> Components;
//        //data["Components"] & Components;
//        //for (auto& c : Components)
//        //{
//        //    c.release();
//        //}
//        //value.Serialize(data);
//        //Memory::GetParentEntity() = {};
//    }
//};
//
//}
