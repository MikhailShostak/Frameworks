#pragma once

namespace System
{
template<typename InterfaceType>
struct PUBLIC_API_EXPORT Extension
{
    using This = Extension;
    System::Path Path {};
    boost::dll::shared_library File {};
    System::ExtensionHandle<InterfaceType> Handle {};
    UniqueReference<InterfaceType> Instance {};
    Extension() = default;
    Extension(Extension &&other) = default;
    Extension &operator =(Extension &&other) = default;

    virtual ~Extension() {}
protected:
    InterfaceType *GetIndirectValue();
public:
    InterfaceType &operator*() { return *GetIndirectValue(); }
    const InterfaceType &operator*() const { return *ConstCast(this)->GetIndirectValue(); }
    InterfaceType *operator->() { return GetIndirectValue(); }
    const InterfaceType *operator->() const { return ConstCast(this)->GetIndirectValue(); }

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual void Load(const System::Path & Path);
    virtual void Unload();

    void Initialize()
    {
    }
};
}
