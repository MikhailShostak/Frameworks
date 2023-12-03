//CLASSGEN GENERATED REGION: Includes
#include "RunningData.gen.h"
#include <MetaObjectSerializationHelper.h>
//CLASSGEN END REGION

//CLASSGEN GENERATED REGION: Namespace
namespace OneStudioProject2
//CLASSGEN END REGION
//CLASSGEN GENERATED REGION: NamespaceBegin
{
//CLASSGEN END REGION

//CLASSGEN GENERATED REGION: ClassImplementation
RunningData::RunningData()
{
}
#if METAOBJECT_SUPPORT || REFLECTION_SUPPORT
void RunningData::serialize(AJSONObject &object) const
{
    Super::serialize(object);
    object.insert("Command", toJSONValue(Command));
    object.insert("Arguments", toJSONValue(Arguments));
}
void RunningData::deserialize(const AJSONObject &object)
{
    Super::deserialize(object);
    AJSONValue value;
    value = AJSONValue();
    object.read("Command", value);
    fromJSONValue(value, Command);
    value = AJSONValue();
    object.read("Arguments", value);
    fromJSONValue(value, Arguments);
}
#endif //METAOBJECT_SUPPORT || REFLECTION_SUPPORT
//CLASSGEN END REGION

//CLASSGEN GENERATED REGION: NamespaceEnd
}
//CLASSGEN END REGION
