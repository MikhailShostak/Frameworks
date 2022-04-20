#pragma once

#include "Memory/AssetHandle.hpp"
#include "Meta/Inheritance.hpp"
#include "Reflection/MetaObjectStorage.hpp"
#include "System/Filesystem.hpp"
#include "Text/String.hpp"

class PUBLIC_API_EXPORT RuntimeAssetStorage
{
    struct PUBLIC_API_EXPORT StorageHandle
    {
        Reflection::BaseMetaObject *MetaObject;
        void *PreAllocatedObject;
        void *SharedObject;
    };

    using StorageType = Map<StringID, StorageHandle>;
    //TODO: this temp function should be replaced with singleton storage for plugin support
    static StorageType &Storage();
public:
    template<typename Type>
    static SharedReference<Type> Find(const StringID &Package)
    {
        SharedReference<Type> object;
        auto it = Storage().find(Package);
        if(it != Storage().end())
        {
            if (DynamicCast<Reflection::MetaObject<Type>>(it->second.MetaObject))
            {
                SharedReference<Meta::RootType<Type>> *BaseSharedObject = nullptr;
                if (it->second.PreAllocatedObject)
                {
                    auto baseObject = Reflection::LowLevel::RestoreBaseObject<Type>(it->second.PreAllocatedObject);
                    BaseSharedObject = new SharedReference<Meta::RootType<Type>>(baseObject);
                    it->second.SharedObject = BaseSharedObject;
                    it->second.PreAllocatedObject = nullptr;
                }
                else
                {
                    BaseSharedObject = ReinterpretCast<SharedReference<Meta::RootType<Type>>>(it->second.SharedObject);
                }

                object = *StaticCast<SharedReference<Type>>(BaseSharedObject);
            }
        }
        return object;
    }

    template<typename Type>
    static SharedReference<Type> Load(const System::Path &PackagePath)
    {
        String Package = PackagePath.stem().generic_string();
        SharedReference<Type> object = Find<Type>(Package);
        if(!object)
        {
            ClassReference<Type> ClassReference = Reflection::Find<Type>();
            auto objectPtr = ClassReference->Create();
            if (Serialization::FromFile(PackagePath, objectPtr))
            {
                SharedReference<Meta::RootType<Type>> *BaseSharedObject = new SharedReference<Meta::RootType<Type>>(Reflection::LowLevel::StoreBaseObject(objectPtr.release()));
                object = *StaticCast<SharedReference<Type>>(BaseSharedObject);
                Storage()[Package] = { StaticCast<Reflection::BaseMetaObject>(ClassReference), nullptr, BaseSharedObject };
            }
        }

        return object;
    }
    
    static void Load(const System::Path &PackagePath)
    {
        String Package = PackagePath.stem().generic_string();
        auto it = Storage().find(Package);
        if(it == Storage().end())
        {
            AssetHandle Handle;
            Serialization::FromFile(PackagePath, Handle);

            auto [ClassReference, BaseObject] = Reflection::LowLevel::CreateBaseObject(Handle.Type, Handle.Values);
            if (BaseObject)
            {
                Storage()[Package] = { StaticCast<Reflection::BaseMetaObject>(ClassReference->get()), BaseObject, nullptr };
            }
        }
    }

    static void LoadFolder(const System::Path &FolderPath, const String &Extension)
    {
        for (const auto& entry : System::RecursiveDirectoryIterator(FolderPath))
        {
            if (entry.is_regular_file() && entry.path().extension() == Extension)
            {
                RuntimeAssetStorage::Load(entry.path());
            }
        }
    }
};
