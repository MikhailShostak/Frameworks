#pragma once

namespace Core
{
struct PUBLIC_API_EXPORT AssetManagerSubsystem
    : public Core::Subsystem
{
    using This = AssetManagerSubsystem;
    using Super = Core::Subsystem;
    Array<System::Path> Folders {};

    virtual ~AssetManagerSubsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Folders"] & Folders;
    }
    virtual void Load();

    void Initialize()
    {
        Super::Initialize();
    }
};
}
