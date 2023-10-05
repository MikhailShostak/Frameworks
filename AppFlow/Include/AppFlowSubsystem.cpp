

namespace AppFlow
{

void AppFlowSubsystem::Load()
{
    for (const auto &WindowID : StartupWindows)
    {
        PushWindow(WindowID);
    }
}

void AppFlowSubsystem::PushWindow(const StringID &WindowID)
{
    const auto &WindowData = Windows.at(WindowID);

    //TODO: optmize this
    auto WindowSubsystem = Core::FindSubsystem<Graphics::WindowSubsystem>();
    auto Window = WindowSubsystem->Create();
    Serialization::Convert(WindowData, *Window);
}

}
