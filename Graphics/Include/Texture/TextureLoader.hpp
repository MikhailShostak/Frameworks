#pragma once

namespace Graphics
{

PUBLIC_API_EXPORT SharedReference<Graphics::Texture> CreateTextureBuffer(const Int3 &size);
PUBLIC_API_EXPORT SharedReference<Graphics::Texture> CreateTexture(const Color &color, const Int3 &size = { 1, 1, 1 });

PUBLIC_API_EXPORT void LoadTexture(Graphics::Texture &texture, const System::Path &path);
PUBLIC_API_EXPORT SharedReference<Graphics::Texture> LoadTexture(const System::Path &path);
PUBLIC_API_EXPORT void SaveTexture(const SharedReference<Graphics::Texture> &texture, const System::Path &path);

}
