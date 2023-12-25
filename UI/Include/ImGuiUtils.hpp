#pragma once

namespace ImGui
{

inline void Image(Graphics::Texture &Texture, const Float2 &Size)
{
    ImTextureID handle = *((ImTextureID*)&Texture.Data);
    if (handle == 0)
    {
        Graphics::GraphicsContext().Create2DTexture(Texture);
        handle = *((ImTextureID*)&Texture.Data);
    }

    ImGui::Image(handle, ImVec2(Size[0], Size[1]));
}

}
