#define NULL_RHI 0
#if NULL_RHI

namespace Graphics
{

Graphics::RenderBuffer/*RenderBuffer*/ RenderTarget::GetBuffer()
{
    Graphics::RenderBuffer buffer;
    return { std::move(buffer) };
}

void RenderTarget::Resize(const hlslpp::int2 &Size)
{
    
}

}

#endif
