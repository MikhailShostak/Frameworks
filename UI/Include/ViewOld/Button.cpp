#include "Button.hpp"

namespace UI
{

void Button::Draw()
{
    ImGui::Button(Text.data(), { float(Size[0]), float(Size[1]) });
}

}
