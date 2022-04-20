#pragma once

#include "Reflection/MetaObjectStorage.hpp"

namespace Reflection
{

namespace LowLevel
{

inline UniqueReference<BaseMetaObject> *Find(const String& name)
{
    auto &Types = Reflection::GetTypes();
    auto it = ranges::find_if(Types, [&name](auto& pair) { return pair.second->m_Name == name; });
    if (it != Types.end())
    {
        return &it->second;
    }
    return nullptr;
}

inline std::pair<UniqueReference<BaseMetaObject> *, void *> CreateBaseObject(const String& name)
{
    UniqueReference<BaseMetaObject> *classReference = Find(name);
    if (!classReference)
    {
        return { nullptr, nullptr };
    }

    return { classReference, (*classReference)->CreateAsBaseObject() };
}

inline std::pair<UniqueReference<BaseMetaObject> *, void *> CreateBaseObject(const String& name, const Serialization::Data &data)
{
    UniqueReference<BaseMetaObject> *classReference = Find(name);
    if (!classReference)
    {
        return { nullptr, nullptr };
    }

    return { classReference, (*classReference)->CreateAsBaseObject(data) };
}

}

template<typename Type>
using ClassReference = Reflection::MetaObject<Type>*;

inline ClassReference<MetaObjectRootType> Find(size_t TypeHash)
{
    auto it = Reflection::GetTypes().find(TypeHash);
    if (it == Reflection::GetTypes().end())
    {
        return nullptr;
    }

    return it->second.get();
}

template<typename Type>
inline ClassReference<Type> Find()
{
    return static_cast<ClassReference<Type>>(Find(typeid(Type).hash_code()));
}

template<typename Type>
inline ClassReference<Type> Find(const String& name)
{
    UniqueReference<BaseMetaObject> *BaseMetaObject = LowLevel::Find(name);
    if (!BaseMetaObject)
    {
        fmt::print("Can't find {} in the reflection system.\n", name);
        assert(false);
        return nullptr;
    }

    ClassReference<Type> CastedType = dynamic_cast<ClassReference<Type>>(BaseMetaObject->get());
    if (!CastedType)
    {
        auto MetaType = Reflection::Find<Type>();
        if (!MetaType)
        {
            fmt::print("Couldn't cast {}. Can't find {} in reflection system.\n", (*BaseMetaObject)->m_Name, typeid(Type).name());
        }
        else
        {
            fmt::print("Couldn't cast {} to {}. Please make sure that data is correct or {} class has Super alias to a base class.\n", (*BaseMetaObject)->m_Name, Reflection::Find<Type>()->m_Name, (*BaseMetaObject)->m_Name);
        }
        assert(false);
    }
    return CastedType;
}

template<typename Type>
inline ClassReference<Type> Find(const Type& Object)
{
    return static_cast<ClassReference<Type>>(Find(typeid(Object).hash_code()));
}

template<typename Type>
inline Array<ClassReference<Type>> FindAll()
{
    return GetTypes()
        | ranges::views::filter([](auto& pair) { return dynamic_cast<ClassReference<Type>>(pair.second.get()); })
        | ranges::views::transform([](auto& pair) { return static_cast<ClassReference<Type>>(pair.second.get()); })
        | ranges::to<Array<ClassReference<Type>>>();
}

template<typename Type>
inline Array<ClassReference<Type>> FindAllDerived()
{
    return GetTypes()
        | ranges::views::filter([](auto& pair) { return typeid(Type).hash_code() != pair.first && dynamic_cast<ClassReference<Type>>(pair.second.get()); })
        | ranges::views::transform([](auto& pair) { return static_cast<ClassReference<Type>>(pair.second.get()); })
        | ranges::to<Array<ClassReference<Type>>>();
}

template<typename Type>
inline UniqueReference<Type> Create(const String& name)
{
    ClassReference<Type> classReference = Find<Type>(name);
    if (!classReference)
    {
        return nullptr;
    }

    return classReference->Create();
}

template<typename Type>
inline SharedReference<Type> CreateShared(const String& name)
{
    ClassReference<Type> classReference = Find<Type>(name);
    if (!classReference)
    {
        return nullptr;
    }

    return classReference->CreateShared();
}

}

using Reflection::ClassReference;
