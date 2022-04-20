#pragma once

#include "Storage.hpp"
#include "Serializer.hpp"

namespace Serialization
{

template<typename Type>
inline InputValue &operator &(InputValue &data, Type &&value)
{
    Serializer<InputValue, std::remove_reference_t<Type>>::Write(data, std::forward<Type>(value));
    return data;
}

template<typename Type>
inline OutputValue &operator &(OutputValue &data, Type &&value)
{
    Serializer<OutputValue, std::remove_reference_t<Type>>::Write(data, std::forward<Type>(value));
    return data;
}

template<typename Type>
inline void Serialize(const Type &value, Data &data)
{
    static_cast<OutputValue&>(data) & const_cast<Type &>(value);
}

template<typename Type>
inline Data Serialize(const Type &value)
{
    Data data;
    Serialization::Serialize(value, data);
    return data;
}

template<typename Type>
inline void Deserialize(const Data &data, Type &value)
{
    static_cast<InputValue &>(const_cast<Data &>(data)) & value;
}

template<typename Type>
inline Type Deserialize(const Data &data)
{
    Type value;
    Serialization::Deserialize(data, value);
    return value;
}

template<typename OutputType, typename InputType>
inline void Convert(const InputType& inputValue, OutputType& outputValue)
{
    Serialization::Deserialize(Serialize(inputValue), outputValue);
}

template<typename OutputType, typename InputType>
inline OutputType Convert(const InputType& inputValue)
{
    return Serialization::Deserialize<OutputType>(Serialize(inputValue));
}

template<typename Type>
inline std::string ToString(const Type &value)
{
    return Serialization::Serialize(value).ToString();
}

template<typename Type>
inline bool ToFile(const Type &value, const std::filesystem::path &path)
{
    return Serialization::Serialize(value).ToFile(path);
}

template<typename Type>
inline void FromString(const std::string &string, Type &value)
{
    Data data;
    data.FromString(string);
    Serialization::Deserialize(data, value);
}

template<typename Type>
inline bool FromFile(const std::filesystem::path &path, Type &value)
{
    Data data;
    if (!data.FromFile(path))
    {
        return false;
    }

    Serialization::Deserialize(data, value);
    return true;
}

}
