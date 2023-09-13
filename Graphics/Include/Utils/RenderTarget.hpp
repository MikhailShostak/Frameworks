#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT RenderTarget
{
    using This = RenderTarget;
    Array<SharedReference<Graphics::Texture>> Targets {};
    SharedReference<Graphics::Texture> DepthStencil {};
    bool IsCompiled {};

    template<typename T>
    void Serialize(T &&data)
    {
    }
    virtual Graphics::RenderBuffer/*RenderBuffer*/ GetBuffer();
    virtual void Resize(const Int2 & Size);

    void Initialize()
    {
    }
};
}
