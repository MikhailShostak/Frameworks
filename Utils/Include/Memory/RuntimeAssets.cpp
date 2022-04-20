#include "RuntimeAssets.hpp"

RuntimeAssetStorage::StorageType &RuntimeAssetStorage::Storage()
{
    static RuntimeAssetStorage::StorageType storage;
    return storage;
}
