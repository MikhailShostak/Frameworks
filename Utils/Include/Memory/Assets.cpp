Map<String, std::pair<size_t, void*>> &AssetStorage::Storage()
{
    static Map<String, std::pair<size_t, void*>> storage;
    return storage;
}
