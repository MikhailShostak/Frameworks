#include "View.hpp"

namespace Experimental::UI
{

View::View()
{
    TextID = fmt::format("{}", fmt::ptr(this));
}

void View::Layout()
{

}

void View::PreDraw()
{
    //TODO: Add ImVec2 Conversion
    //ImGui::SetCursorPos(ImVec2{Position[0], Position[1]});
}

void View::Draw()
{
    //ImGui::BeginChild(TextID.data());
    for (auto &v : Views)
    {
        v->Update();
    }
    //ImGui::EndChild();
}

void View::PostDraw()
{
    /*if (g_Debug)
    {
        ImGui::Line(m_TextID, {});
    }*/
}

void View::Update()
{
    Layout();
    PreDraw();
    Draw();
    PostDraw();
}


}
