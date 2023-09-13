#pragma once

namespace Graphics
{
struct PUBLIC_API_EXPORT RenderBuffer
{
    using This = RenderBuffer;
    InplaceStorage<RenderBufferPrivateData, 88, 8, false> Data;
    RenderBuffer();
    RenderBuffer(const RenderBuffer &other);
    RenderBuffer &operator =(const RenderBuffer &other);
    RenderBuffer(RenderBuffer &&other);
    RenderBuffer &operator =(RenderBuffer &&other);

     ~RenderBuffer();
    template<typename T>
    void Serialize(T &&data)
    {
    }

    void Initialize()
    {
    }
};
}
