#pragma once

namespace Core
{

PUBLIC_API_EXPORT Array<SharedReference<Core::Subsystem>> &GetSubsystems();
PUBLIC_API_EXPORT int Run(const System::Path &ConfigPath);

template<typename Type>
inline SharedReference<Type> FindSubsystem()
{
    for (auto &subsystem : GetSubsystems())
    {
        auto s = DynamicCast<Type>(subsystem);
        if (s)
        {
            return s;
        }
    }

    return nullptr;
}

}
