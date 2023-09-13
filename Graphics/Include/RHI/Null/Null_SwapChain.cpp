#define NULL_RHI 1
#if NULL_RHI

namespace Graphics
{

SwapChain::SwapChain() = default;
SwapChain::SwapChain(SwapChain&& other) = default;
SwapChain& SwapChain::operator =(SwapChain&& other) = default;
SwapChain::~SwapChain() = default;

void SwapChain::Resize(const hlslpp::int2 &resolution)
{
    
}

Graphics::RenderBuffer/*RenderBuffer*/ SwapChain::GetRenderBuffer()
{
    Graphics::RenderBuffer buffer;
    return buffer;
}

void SwapChain::Swap()
{
    
}

}

#endif
