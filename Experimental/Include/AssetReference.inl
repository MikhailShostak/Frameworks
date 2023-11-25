
template<typename Type>
inline Type* AssetReference<Type>::GetIndirectValue()
{
    return &Data;
}

template<typename Type>
inline bool AssetReference<Type>::Load()
{
    return Serialization::FromFile(Path, Data);
}

template<typename Type>
inline bool AssetReference<Type>::Save()
{
    return Serialization::ToFile(Data, Path);
}
