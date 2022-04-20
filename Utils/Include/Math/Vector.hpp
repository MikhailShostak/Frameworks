#pragma once

#include "Serialization/Serializer.hpp"

using Float2 = hlslpp::float2;
using Float3 = hlslpp::float3;
using Float4 = hlslpp::float4;

using Int2 = hlslpp::int2;
using Int3 = hlslpp::int3;
using Int4 = hlslpp::int4;

namespace Math
{

template<uint8_t x, uint8_t y = 1, typename Type>
inline constexpr Type Swizzle2(const Type &Value)
{
    union
    {
        hlslpp::swizzle2<x, y> Input;
        hlslpp::swizzle2<0, 1> Output;
    };

    Input = Value;
    return Output;
}

template<typename Type>
inline constexpr Type Swizzle2(const Type &Value, const Int2 &Swizzle)
{
    return {
        Value[Swizzle[0]],
        Value[Swizzle[1]]
    };
}

template<uint8_t x, uint8_t y = 1, uint8_t z = 2, typename Type>
inline constexpr Type Swizzle3(const Type &Value)
{
    union
    {
        hlslpp::swizzle3<x, y, z> Input;
        hlslpp::swizzle3<0, 1, 2> Output;
    };

    Input = Value;
    return Output;
}

template<typename Type>
inline constexpr Type Swizzle3(const Type &Value, const Int3 &Swizzle)
{
    return {
        Value[Swizzle[0]],
        Value[Swizzle[1]],
        Value[Swizzle[2]]
    };
}

template<uint8_t x, uint8_t y = 1, uint8_t z = 2, uint8_t w = 3, typename Type>
inline constexpr Type Swizzle4(const Type &Value)
{
    union
    {
        hlslpp::swizzle4<x, y, z, w> Input;
        hlslpp::swizzle4<0, 1, 2, 3> Output;
    };

    Input = Value;
    return Output;
}

template<typename Type>
inline constexpr Type Swizzle4(const Type &Value, const Int4 &Swizzle)
{
    return {
        Value[Swizzle[0]],
        Value[Swizzle[1]],
        Value[Swizzle[2]],
        Value[Swizzle[3]]
    };
}

}

namespace Serialization
{

template<>
struct ObjectSerializer<Int2>
{
    template<typename DataType, typename ValueType>
    static void Serialize(DataType&& data, ValueType&& value)
    {
        data["X"] & value.i32[0];
        data["Y"] & value.i32[1];
    }
};

template<>
struct ObjectSerializer<Int3>
{
    template<typename DataType, typename ValueType>
    static void Serialize(DataType&& data, ValueType&& value)
    {
        data["X"] & value.i32[0];
        data["Y"] & value.i32[1];
        data["Z"] & value.i32[2];
    }
};

template<>
struct ObjectSerializer<Int4>
{
    template<typename DataType, typename ValueType>
    static void Serialize(DataType&& data, ValueType&& value)
    {
        data["X"] & value.i32[0];
        data["Y"] & value.i32[1];
        data["Z"] & value.i32[2];
        data["W"] & value.i32[3];
    }
};

template<>
struct ObjectSerializer<Float2>
{
    template<typename DataType, typename ValueType>
    static void Serialize(DataType&& data, ValueType&& value)
    {
        data["X"] & value.f32[0];
        data["Y"] & value.f32[1];
    }
};

template<>
struct ObjectSerializer<Float3>
{
    template<typename DataType, typename ValueType>
    static void Serialize(DataType&& data, ValueType&& value)
    {
        data["X"] & value.f32[0];
        data["Y"] & value.f32[1];
        data["Z"] & value.f32[2];
    }
};

template<>
struct ObjectSerializer<Float4>
{
    template<typename DataType, typename ValueType>
    static void Serialize(DataType&& data, ValueType&& value)
    {
        data["X"] & value.f32[0];
        data["Y"] & value.f32[1];
        data["Z"] & value.f32[2];
        data["W"] & value.f32[3];
    }
};

}
