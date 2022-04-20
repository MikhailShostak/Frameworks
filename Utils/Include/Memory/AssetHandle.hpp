#pragma once

struct PUBLIC_API_EXPORT AssetHandle
{
    using This = AssetHandle;
    String Type {};
    Serialization::Data Values {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Type"] & Type;
        data["Values"] & Values;
    }

    void Initialize()
    {
    }
};
