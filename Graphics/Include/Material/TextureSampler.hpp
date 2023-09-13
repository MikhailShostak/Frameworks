#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT TextureSampler
{
    using This = TextureSampler;
    String Name {};
    SharedReference<Graphics::Texture> Texture {};
    ShaderFlags Flags {};
    TextureSampler();

    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
}
