#pragma once

namespace AppFlow
{
struct PUBLIC_API_EXPORT WindowData
{
    using This = WindowData;
    Map<String, String> Scene {};
    String Title {};
    Int2 Position {};
    Int2 Size {};
    Graphics::WindowMode Mode {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Scene"] & Scene;
        data["Title"] & Title;
        data["Position"] & Position;
        data["Size"] & Size;
        data["Mode"] & Mode;
    }

    void Initialize()
    {
    }
};
}
