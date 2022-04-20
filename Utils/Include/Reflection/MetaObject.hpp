#pragma once

#include "Memory/Allocation.hpp"
#include "Memory/References.hpp"
#include "Serialization/Serialization.hpp"
#include "Text/String.hpp"

namespace Reflection
{

namespace LowLevel
{

template<typename Type>
inline void* StoreBaseObject(Type *Object)
{
    return static_cast<Meta::RootType<Type> *>(Object);
}

template<typename Type>
inline const void* StoreBaseObject(const Type *Object)
{
    return static_cast<const Meta::RootType<Type> *>(Object);
}

template<typename Type>
inline Meta::RootType<Type> *RestoreBaseObject(void *Object)
{
    return reinterpret_cast<Meta::RootType<Type> *>(Object);
}

template<typename Type>
inline const Meta::RootType<Type> *RestoreBaseObject(const void *Object)
{
    return reinterpret_cast<const Meta::RootType<Type> *>(Object);
}

}

template<typename ClassType>
struct MetaObject : public MetaObject<typename Meta::GetBaseType<ClassType>::Type>
{
    using Super = MetaObject<typename Meta::GetBaseType<ClassType>::Type>;

    MetaObject(const char *name)
    {
        Super::m_Name = name;
        Super::ConstructorFunction = []() -> void* { return CreateAs<ClassType, Meta::RootType<ClassType>>(); };
        Super::DestructorFunction = &::DestroyAs<ClassType>;
        if constexpr (true) //TODO: disable if serialization is not implemented for class
        {
            Super::SerializeFunction = [](const void *object, Serialization::Data &data)
            {
                auto base = LowLevel::RestoreBaseObject<ClassType>(object);
                auto derived = static_cast<const ClassType *>(base);
                Serialization::Serialize(*derived, data);
            };
            Super::DeserializeFunction = [](const Serialization::Data &data, void *object)
            {
                auto base = LowLevel::RestoreBaseObject<ClassType>(object);
                auto derived = static_cast<ClassType *>(base);
                Serialization::Deserialize(data, *derived);
            };
        }
    }

    UniqueReference<ClassType> Create()
    {
        auto base = LowLevel::RestoreBaseObject<ClassType>(Super::CreateAsBaseObject());
        return UniqueReference<ClassType>{ static_cast<ClassType *>(base) };
    }

    SharedReference<ClassType> CreateShared()
    {
        auto base = LowLevel::RestoreBaseObject<ClassType>(Super::CreateAsBaseObject());
        return SharedReference<ClassType>{ static_cast<ClassType *>(base) };
    }

protected:
    MetaObject() {}
};

using MetaObjectRootType = Meta::False;

template<>
struct MetaObject<MetaObjectRootType>
{
public:
    virtual ~MetaObject() {};

    const char *m_Name = nullptr;
    template<typename ClassType>
    void Serialize(const ClassType &value, Serialization::Data &data) const
    {
        auto base = LowLevel::StoreBaseObject<ClassType>(&value);
        SerializeFunction(base, data);
    }
    template<typename ClassType>
    void Deserialize(const Serialization::Data &data, ClassType &value) const
    {
        auto base = LowLevel::StoreBaseObject<ClassType>(&value);
        DeserializeFunction(data, base);
    }

    void* CreateAsBaseObject()
    {
        return ConstructorFunction();
    }

    void* CreateAsBaseObject(const Serialization::Data &data)
    {
        auto base = CreateAsBaseObject();
        DeserializeFunction(data, base);
        return base;
    }
protected:
    Meta::ConstructorPointer<void> ConstructorFunction;
    Meta::DestructorPointer<void> DestructorFunction;
    Meta::VoidFunctionPointer<const void *, Serialization::Data &> SerializeFunction;
    Meta::VoidFunctionPointer<const Serialization::Data &, void *> DeserializeFunction;
};

}
