#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT Material
{
    using This = Material;
    Graphics::Shader VertexShader {};
    Graphics::Shader PixelShader {};
    Array<TextureSampler> TextureSamplers {};
    bool IsCompiled {};
    Graphics::MaterialRenderingSettings Settings {};
    Graphics::RenderBuffer RenderBuffer {};

    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
}
