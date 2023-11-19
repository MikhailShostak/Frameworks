#include "Button.hpp"

namespace Experimental::UI
{

void Button::Draw()
{
    ImGui::Button(Text.data(), { float(Size[0]), float(Size[1]) });
}

}
