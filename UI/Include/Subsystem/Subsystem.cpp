#pragma once

namespace UI2
{

/*bool OnHandleEvent(Core::Context &Context, const sf::Event &Event) override
{
    return ImGui::IsAnyItemHovered() || ImGui::IsAnyItemActive();
}*/

void Subsystem::RenderScene(Graphics::Window &Window, Graphics::Scene &Scene)
{
    ++Frames;
    Time += Scene.DeltaTime.count();
    if (Time > 0.5f)
    {
        FPS = int32_t(std::round(float(Frames) / Time));
        Frames = 0;
        Time = 0.0f;
    }

    if (RootView)
    {
        RootView->Draw(Scene);
    }

    ImGui::Begin("Debug View");
    ImGui::Text(fmt::format("FPS: {}\nFrame: {}ms\n", FPS, std::chrono::duration_cast<DateTime::Milliseconds>(Scene.DeltaTime).count()).data());
    ImGui::End();
}

}
