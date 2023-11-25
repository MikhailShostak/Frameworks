#pragma once

namespace Serialization
{

template<typename Type, typename Period>
struct PUBLIC_API_EXPORT Serializer<InputValue, std::chrono::duration<Type, Period>>
{
    template<typename InputValue, typename ValueType>
    static void Write(InputValue&& data, ValueType&& value)
    {
        if (data.m_Storage.IsScalar())
        {
            auto v = data.m_Storage.template as<Type>();
            value = std::chrono::duration<Type, Period>(v);
        }
    }
};

template<typename Type, typename Period>
struct PUBLIC_API_EXPORT Serializer<OutputValue, std::chrono::duration<Type, Period>>
{
    template<typename OutputValue, typename ValueType>
    static void Write(OutputValue&& data, ValueType&& value)
    {
        data.m_Storage = value.count();
    }
};

}
