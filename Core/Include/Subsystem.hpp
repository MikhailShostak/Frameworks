#pragma once

namespace Core
{
struct PUBLIC_API_EXPORT Subsystem
{
    using This = Subsystem;
    bool Enabled {};
    Subsystem();

    virtual ~Subsystem() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void Load();
    virtual void Unload();
    virtual void Update();

    void Initialize()
    {
    }
};
}
