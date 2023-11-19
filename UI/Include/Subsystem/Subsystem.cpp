#pragma once

namespace UI2
{

/*bool OnHandleEvent(Core::Context &Context, const sf::Event &Event) override
{
    return ImGui::IsAnyItemHovered() || ImGui::IsAnyItemActive();
}*/

bool Initialized = false;
ImFont* DefaultUIFont = nullptr;
ImFont* DefaultMonospacedFont = nullptr;

std::queue<std::function<void()>> Queue;

void Subsystem::PreUpdate(Graphics::Window &Window, Graphics::Scene &Scene)
{
    if (!Initialized)
    {
        Initialized = true;
#if BOOST_OS_WINDOWS
        LoadFont("C:/Windows/Fonts/consola.ttf", 10_pt, nullptr, nullptr, [](ImFont *Font){ DefaultMonospacedFont = Font; });
        LoadFont("C:/Windows/Fonts/segoeui.ttf", 12_pt, nullptr, nullptr, [](ImFont *Font){ DefaultUIFont = Font; });
#else
        ImFont* font = ImGui::GetDefaultFont();
        DefaultMonospacedFont = font;
        DefaultUIFont = font;
#endif
    }

    while (!Queue.empty())
    {
        Queue.front()();
        Queue.pop();
    }
}

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

    PushUIFont();
    if (RootView)
    {
        RootView->Draw(Scene);
    }
    ImGui::PopFont();

    PushMonospacedFont();
    ImGui::Begin("Debug View");
    ImGui::Text(fmt::format("FPS: {}\nFrame: {}ms\nWindow DeltaTime: {:.10}s\nScene DeltaTime: {:.10}s",
        FPS,
        std::chrono::duration_cast<DateTime::Milliseconds>(Scene.DeltaTime).count(),
        Window.DeltaTime.count(),
        Scene.DeltaTime.count()
    ).data());
    ImGui::End();
    ImGui::PopFont();
}

void Subsystem::PushUIFont()
{
    ImGui::PushFont(DefaultUIFont);
}

void Subsystem::PushMonospacedFont()
{
    ImGui::PushFont(DefaultMonospacedFont);
}

void Subsystem::PopFont()
{
    ImGui::PopFont();
}

void Subsystem::LoadFont(const System::Path& Path, const fpixel_t Size, ImFontConfig* Config, const unsigned short* GlyphRange, const std::function<void(ImFont*)> & Callback)
{
    Queue.push([=]()
    {
        ImGuiIO& io = ImGui::GetIO();
        auto Font = io.Fonts->AddFontFromFileTTF(Path.generic_string().data(), Size, Config, GlyphRange);
        FontsDirty = true;
        Callback(Font);
    });
}

}
