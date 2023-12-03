#pragma once

//CLASSGEN GENERATED REGION: Includes
#include "Serializable.h"
#include <LegacyMath.hpp>
#include <LegacyFoundation.hpp>

//CLASSGEN END REGION
#include <LegacyGraphics.hpp>
//CLASSGEN GENERATED REGION: Namespace
namespace Core
//CLASSGEN END REGION
//CLASSGEN GENERATED REGION: NamespaceBegin
{
//CLASSGEN END REGION

//CLASSGEN GENERATED REGION: ClassHeader
class PUBLIC_API_EXPORT Space : public Serializable
//CLASSGEN END REGION
{
//CLASSGEN GENERATED REGION: ClassBody
public:
    typedef Space This;
    typedef Serializable Super;
    typedef void Interfaces;
protected:
    Array<SharedReference<Core::Entity>> Entities;
public:
    Space();
#if METAOBJECT_SUPPORT || REFLECTION_SUPPORT
    void serialize(class AJSONObject &object) const;
    void deserialize(const class AJSONObject &object);
#endif //METAOBJECT_SUPPORT || REFLECTION_SUPPORT
    Array<SharedReference<Core::Entity>> getEntities() const;
    void setEntities(Array<SharedReference<Core::Entity>> const &Entities);
    void setEntities(Array<SharedReference<Core::Entity>> &&Entities);
//CLASSGEN END REGION
};

//CLASSGEN GENERATED REGION: NamespaceEnd
}
//CLASSGEN END REGION
