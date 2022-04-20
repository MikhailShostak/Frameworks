#pragma once

namespace System
{
template<typename InterfaceType>
struct PUBLIC_API_EXPORT ExtensionLibrary
{
    using This = ExtensionLibrary;
    System::Path Root {};
    Array<Extension<InterfaceType>> Extensions {};
    ExtensionLibrary() = default;
    ExtensionLibrary(ExtensionLibrary &&other) = default;
    ExtensionLibrary &operator =(ExtensionLibrary &&other) = default;

    virtual ~ExtensionLibrary() {}
    template<typename T>
    void Serialize(T &&data)
    {
        data["Root"] & Root;
    }
    virtual void Load();
    virtual void Load(const System::Path & Directory);
    virtual void Unload();

    void Initialize()
    {
    }
};
}
