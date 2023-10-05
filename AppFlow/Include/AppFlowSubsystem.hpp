#pragma once

namespace AppFlow
{
struct PUBLIC_API_EXPORT AppFlowSubsystem
    : public Core::Subsystem
{
    using This = AppFlowSubsystem;
    using Super = Core::Subsystem;
    Map<StringID, AppFlow::WindowData> Windows {};
    Array<StringID> StartupWindows {};

    virtual ~AppFlowSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Windows"] & Windows;
        data["StartupWindows"] & StartupWindows;
    }
    virtual void Load();
    virtual void PushWindow(const StringID & WindowID);

    void Initialize()
    {
        Super::Initialize();
    }
};
}
