#pragma once

namespace ECS
{
struct PUBLIC_API_EXPORT SpriteMaterial
{
    using This = SpriteMaterial;
    System::Path Path {};
    SharedReference<sf::Texture> TextureInstance {};
    Int2 Offset {};
    Int2 Size {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["Path"] & Path;
        data["Offset"] & Offset;
        data["Size"] & Size;
    }

    void Initialize()
    {
    }
};
}
