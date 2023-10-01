static Array<SharedReference<Core::Subsystem>> g_Subsystems;
static bool g_Running = true;
static int32_t g_ErrorCode = 0;

namespace Core
{

Array<SharedReference<Subsystem>> &GetSubsystems()
{
    static Array<SharedReference<Subsystem>> Subsystems;
    return Subsystems;
}

int Run(const System::Path &ConfigPath)
{
    auto &subsystems = Core::GetSubsystems();
    Serialization::FromFile(ConfigPath, subsystems);
    
    for (auto &subsystem : subsystems)
    {
        subsystem->Load();
    }

    while (g_Running)
    {
        for (auto& subsystem : subsystems)
        {
            if (subsystem->Enabled)
            {
                subsystem->Update();
            }
        }
    }

    for (auto& subsystem : subsystems)
    {
        subsystem->Unload();
    }

    return g_ErrorCode;
}

}
