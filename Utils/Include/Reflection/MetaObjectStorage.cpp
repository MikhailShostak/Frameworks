#include "Containers/Map.hpp"
#include "Memory/References.hpp"
#include "Reflection/MetaObjectStorage.hpp"

namespace Reflection
{

PUBLIC_API_EXPORT std::unordered_map<size_t, std::unique_ptr<BaseMetaObject>>& GetTypes()
{
    static std::unordered_map<size_t, std::unique_ptr<BaseMetaObject>> Types;
    return Types;
}

}
