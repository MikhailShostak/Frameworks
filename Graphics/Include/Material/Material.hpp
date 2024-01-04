#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT Material
{
    using This = Material;
    System::Path SourceShaderPath {};
    Graphics::Shader VertexShader {};
    Graphics::Shader PixelShader {};
    Array<TextureSampler> TextureSamplers {};
    bool IsCompiled {};
    Graphics::MaterialRenderingSettings Settings {};
    Graphics::RenderBuffer RenderBuffer {};

    template<typename T>
    void Serialize(T &&data)
    {
        data["SourceShaderPath"] & SourceShaderPath;
        data["VertexShader"] & VertexShader;
        data["PixelShader"] & PixelShader;
        data["TextureSamplers"] & TextureSamplers;
        data["Settings"] & Settings;
    }

    void Initialize()
    {
    }
};
}
