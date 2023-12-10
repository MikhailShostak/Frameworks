#pragma once

//CLASSGEN GENERATED REGION: Includes
#include "Entry.gen.h"
#include <LegacyFoundation.hpp>

//CLASSGEN END REGION

//CLASSGEN GENERATED REGION: Namespace
namespace LegacyClassGen
//CLASSGEN END REGION
//CLASSGEN GENERATED REGION: NamespaceBegin
{
//CLASSGEN END REGION

//CLASSGEN GENERATED REGION: ClassHeader
class FunctionEntry : public LegacyClassGen::Entry
//CLASSGEN END REGION
{
//CLASSGEN GENERATED REGION: ClassBody
public:
    typedef FunctionEntry This;
    typedef LegacyClassGen::Entry Super;
    typedef void Interfaces;
public:
    FunctionEntry();
#if METAOBJECT_SUPPORT || REFLECTION_SUPPORT
    void serialize(class AJSONObject &object) const;
    void deserialize(const class AJSONObject &object);
#endif //METAOBJECT_SUPPORT || REFLECTION_SUPPORT
    String /*Code*/ generate(Array<String> const& Parameters);
//CLASSGEN END REGION
};

//CLASSGEN GENERATED REGION: NamespaceEnd
}
//CLASSGEN END REGION