#define NULL_RHI 0
#if NULL_RHI

namespace Graphics
{

GraphicsContext::GraphicsContext() = default;
GraphicsContext::GraphicsContext(GraphicsContext && other) = default;
GraphicsContext& GraphicsContext::operator =(GraphicsContext && other) = default;
GraphicsContext::~GraphicsContext() = default;

bool/*Result*/ GraphicsContext::Initialize(const Graphics::NativeWindow &NativeWindow, Graphics::SwapChain &SwapChain)
{
    return true;
}

void GraphicsContext::CreateDrawBatch(Graphics::DrawBatchBase &Batch)
{
    
}

void GraphicsContext::CreateConstants(Graphics::ShaderMetatype &Constants)
{
    
}

void GraphicsContext::CreateMesh(Graphics::Mesh &Mesh)
{

}

enum class TextureBufferType
{
    Texture,
    RenderTarget,
    DepthStencil
};

void GraphicsContext::Create2DTexture(Graphics::Texture &Texture)
{

}

void GraphicsContext::CreateRenderTarget(Graphics::RenderTarget &RenderTarget)
{
    
}

void GraphicsContext::CreateMaterial(Graphics::Material &Material)
{
    
}

void GraphicsContext::ClearRenderBuffers(const hlslpp::float4 &Color)
{
    
}

void GraphicsContext::ClearDepthBuffer(float Value)
{
    
}

void GraphicsContext::ClearStencilBuffer(uint8_t Value)
{
    
}

void GraphicsContext::ClearDepthStencilBuffers(float DepthValue, uint8_t StencilValue)
{
    
}

void GraphicsContext::SetRenderBuffer(const Graphics::RenderBuffer &buffer)
{
    
}
void GraphicsContext::Render(Graphics::SwapChain &SwapChain)
{
    
}

void GraphicsContext::Upload(Graphics::DrawBatchBase &Batch)
{
    
}

void GraphicsContext::ApplyConstants(Graphics::ShaderMetatype &Constants)
{
    
}

void GraphicsContext::SetState(PipelineState &State)
{
    
}

void GraphicsContext::Draw(Graphics::Mesh &Mesh, Graphics::DrawBatchBase &Batch)
{
    
}

void GraphicsContext::ApplyMaterial(Graphics::Material &material)
{
    
}

void GraphicsContext::InvalidateMaterial(Graphics::Material& material)
{
    
}

}

#endif
