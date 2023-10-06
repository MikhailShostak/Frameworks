#pragma once

struct PUBLIC_API_EXPORT GameMode
{
    using This = GameMode;

    virtual ~GameMode() {}
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
