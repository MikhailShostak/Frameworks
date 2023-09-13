#include "View/View.hpp"
#include "Subsystem/Subsystem.hpp"

namespace
{

struct UIReflectionType
{
    UIReflectionType()
    {
        Reflection::Add<UI2::View>("UI2.View");
        Reflection::Add<UI2::Subsystem>("UI2.Subsystem");
    }
} inline UIReflection;

}
