#pragma once

#include "Reflection/MetaObject.hpp"

namespace Reflection
{

using BaseMetaObject = MetaObject<MetaObjectRootType>;

//TODO: this temp function should be replaced with singleton storage for plugin support
PUBLIC_API_EXPORT std::unordered_map<size_t, std::unique_ptr<BaseMetaObject>>& GetTypes();

template<typename Type>
inline void Add(const char* name)
{
    GetTypes().insert({ typeid(Type).hash_code(), std::make_unique<MetaObject<Type>>(name) });
}

template<typename Type>
inline void Remove()
{
    GetTypes().erase(typeid(Type).hash_code());
}

}
