#include "View/View.hpp"
#include "Subsystem/Subsystem.hpp"

namespace
{

struct UIReflectionType
{
    UIReflectionType()
    {
        //Reflection::Add<UI::Button>("UI.Button");
        //Reflection::Add<UI::Label>("UI.Label");
        //Reflection::Add<UI::TextField>("UI.TextField");
        //Reflection::Add<UI::View>("UI.View");
        Reflection::Add<UI2::View>("UI2.View");
        Reflection::Add<UI2::Subsystem>("UI2.Subsystem");
    }
} inline UIReflection;

}
