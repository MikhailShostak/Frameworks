#include "Label.hpp"

namespace Experimental::UI
{

void TextField::Draw()
{
    ImGui::PushItemWidth(float(Size.x));
    ImGui::InputText(("##" + TextID).data(), &Text);
    ImGui::PopItemWidth();
}

}