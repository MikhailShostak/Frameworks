#pragma once

namespace ImGui
{

inline void Image(Graphics::Texture &Texture, const Float2 &Size = { 0, 0 }, const Float4& UV = {0, 0, 1, 1}, const Float4& TintColor = {1, 1, 1, 1}, const Float4& BorderColor = {0, 0, 0, 0})
{
    ImTextureID handle = *((ImTextureID*)&Texture.Data);
    if (handle == 0)
    {
        Graphics::GraphicsContext().Create2DTexture(Texture);
        handle = *((ImTextureID*)&Texture.Data);
    }

    ImGui::Image(
        handle,
        { Size[0] != 0.0f ? Size[0] : Texture.Size[0], Size[1] != 0.0f ? Size[1] : Texture.Size[1] },
        { UV[0], UV[1] },
        { UV[2], UV[3] },
        { TintColor[0], TintColor[1], TintColor[2], TintColor[3] },
        { BorderColor[0], BorderColor[1], BorderColor[2], BorderColor[3] }
    );
}

inline void Image(const SharedReference<Graphics::Texture> &Texture, const Float2 &Size = { 0, 0 }, const Float4& UV = {0, 0, 1, 1}, const Float4& TintColor = {1, 1, 1, 1}, const Float4& BorderColor = {0, 0, 0, 0})
{
    Image(*Texture, Size, UV, TintColor, BorderColor);
}

}
